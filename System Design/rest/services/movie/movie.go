package movie

import (
	"encoding/json"
	"fmt"
	"net/http"

	database "example.com/ivanj26/rest/db"
	"example.com/ivanj26/rest/models"
	"github.com/gorilla/mux"
)

type IMovieService interface {
	GetMovies(w http.ResponseWriter, r *http.Request)
	GetMovie(w http.ResponseWriter, r *http.Request)
	DeleteMovie(w http.ResponseWriter, r *http.Request)
	DeleteMovies(w http.ResponseWriter, r *http.Request)
	CreateMovie(w http.ResponseWriter, r *http.Request)
}

type MovieService struct{}

func NewMovieService() IMovieService {
	return MovieService{}
}

// Get movie service...
func (m MovieService) GetMovies(w http.ResponseWriter, r *http.Request) {
	db := database.SetupDB()

	fmt.Println("Getting movies from database...")

	// Get all movies from movies table that don't have movieID = "1"
	rows, err := db.Query("SELECT * FROM movies")
	if err != nil {
		panic(err)
	}

	// var response []JsonResponse
	var movies []models.Movie

	// Foreach movie
	defer rows.Close()
	for rows.Next() {
		var id int
		var movieID string
		var movieName string

		err = rows.Scan(&id, &movieID, &movieName)

		// check errors
		if err != nil {
			panic(err)
		}

		movies = append(movies, models.Movie{MovieID: movieID, MovieName: movieName})
	}

	db.Close()

	var response = models.JsonResponse{Type: "success", Data: movies}

	json.NewEncoder(w).Encode(response)
}

func (m MovieService) GetMovie(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)
	movieID := params["movieId"]

	var response = models.JsonResponse{}

	if len(movieID) == 0 {
		response = models.JsonResponse{
			Type:    "error",
			Message: "You are missing movieID parameter.",
		}
	} else {
		db := database.SetupDB()

		fmt.Printf("Get movie with id:%s from database\n", movieID)

		row, err := db.Query("SELECT * FROM movies WHERE movieid = $1", movieID)

		// check error
		if err != nil {
			panic(err)
		}

		var id int
		var movieName string
		var movieID string

		defer row.Close()

		row.Next()
		err = row.Scan(&id, &movieID, &movieName)

		if err != nil {
			panic(err)
		}

		db.Close()

		response = models.JsonResponse{
			Type: "success",
			Data: models.Movie{
				MovieID:   movieID,
				MovieName: movieName,
			},
		}
	}

	json.NewEncoder(w).Encode(response)
}

// Delete movie service...
func (m MovieService) DeleteMovie(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)
	movieID := params["movieId"]

	var response = models.JsonResponse{}

	if len(movieID) == 0 {
		response = models.JsonResponse{Type: "error", Message: "You are missing movieID parameter."}
	} else {
		db := database.SetupDB()

		fmt.Println("Deleting movie from database...")

		_, err := db.Exec("DELETE FROM movies where movieID = $1", movieID)

		// check errors
		if err != nil {
			panic(err)
		}

		db.Close()

		response = models.JsonResponse{Type: "success", Message: "The movie has been deleted successfully!"}
	}

	json.NewEncoder(w).Encode(response)
}

// Delete list of movie service...
func (m MovieService) DeleteMovies(w http.ResponseWriter, r *http.Request) {
	db := database.SetupDB()

	fmt.Println("Deleting all movies...")

	_, err := db.Exec("DELETE FROM movies")

	// check errors
	if err != nil {
		panic(err)
	}

	var response = models.JsonResponse{Type: "success", Message: "All movies have been deleted successfully!"}

	json.NewEncoder(w).Encode(response)
}

// Store new movie service...
func (m MovieService) CreateMovie(w http.ResponseWriter, r *http.Request) {
	movieName := r.FormValue("movieName")

	var response models.JsonResponse
	if len(movieName) == 0 {
		response = models.JsonResponse{
			Type:    "error",
			Message: "Missing payload",
		}
	} else {
		db := database.SetupDB()

		err := db.QueryRow("INSERT INTO movies(movie_name) VALUES($2);", movieName).Err()
		if err != nil {
			panic(err)
		}

		db.Close()
	}

	json.NewEncoder(w).Encode(response)
}
