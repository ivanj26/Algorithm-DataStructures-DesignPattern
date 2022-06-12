package db

import (
	"database/sql"
	"fmt"
	"os"

	_ "github.com/lib/pq"
)

const (
	DB_USER = "ivan.jonathan"
	DB_PASS = "root"
	DB_NAME = "example"
)

func SetupDB() *sql.DB {
	dbinfo := fmt.Sprintf("user=%s password=%s dbname=%s sslmode=disable", DB_USER, DB_PASS, DB_NAME)
	db, err := sql.Open("postgres", dbinfo)

	if err != nil {
		fmt.Println("Failed to open database connection!")
		os.Exit(1)
	}

	return db
}
