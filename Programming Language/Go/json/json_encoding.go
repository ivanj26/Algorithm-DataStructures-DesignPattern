package main

import (
    "bufio"
    "bytes"
    "encoding/json"
    "fmt"
    "io"
    "io/ioutil"
    "os"
    "strconv"
    "strings"
)

type Manager struct {
    FullName       string `json:"full_name,omitempty"`
    Position       string `json:"position,omitempty"`
    Age            int32 `json:"age,omitempty"`
    YearsInCompany int32 `json:"years_in_company,omitempty"`
}

/*
 * Complete the 'EncodeManager' function below and the struct Manager.
 *
 * The function is expected to return an io.Reader and an error.
 * The function accepts *Manager manager as parameter.
 */

func EncodeManager(manager *Manager) (io.Reader, error) {
    out, err := json.Marshal(manager)
    if err != nil {
        return nil, err
    }
    
    reader := bytes.NewReader(out)
    
    return reader, nil
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 16 * 1024 * 1024)

    manager := &Manager{}
    
    fullName := readLine(reader)
    if fullName != "" {
        manager.FullName = fullName
    }
    
    position := readLine(reader)
    if position != "" {
        manager.Position = position
    }
    
    ageTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)
    age := int32(ageTemp)
    if age != 0 {
        manager.Age = age
    }
    
    yearsInCompanyTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)
    yearsInCompany := int32(yearsInCompanyTemp)
    if yearsInCompany != 0 {
        manager.YearsInCompany = yearsInCompany
    }

    resultReader, err := EncodeManager(manager)
    checkError(err)
    
    result, err := ioutil.ReadAll(resultReader)
    checkError(err)

    fmt.Fprintf(writer, "%s\n", string(result))

    writer.Flush()
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}
