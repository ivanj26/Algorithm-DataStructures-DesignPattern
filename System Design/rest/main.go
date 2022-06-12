package main

import (
	"fmt"
	"log"
	"net/http"

	"example.com/ivanj26/rest/services/movie"
	"github.com/gorilla/mux"
)

func main() {
	// Init router
	router := mux.NewRouter()

	// init services
	movieService := movie.NewMovieService()

	// Endpoint list
	router.HandleFunc("/movies/", movieService.GetMovies).Methods("GET")
	router.HandleFunc("/movies/{movieId}", movieService.GetMovie).Methods("GET")
	router.HandleFunc("/movies/", movieService.CreateMovie).Methods("POST")
	router.HandleFunc("/movies/{movieId}", movieService.DeleteMovie).Methods("DELETE")
	router.HandleFunc("/movies/", movieService.DeleteMovies)

	fmt.Println("Server at 8080")
	log.Fatal(http.ListenAndServe(":8080", router))
}
