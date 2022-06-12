package models

type Movie struct {
	MovieID   string `json:"movie_id"`
	MovieName string `json:"movie_name"`
}

type JsonResponse struct {
	Type    string      `json:"type"`
	Data    interface{} `json:"data"`
	Message string      `json:"message"`
}
