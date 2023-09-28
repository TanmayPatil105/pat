# pat: `touch` with affection

The pat command generates a file and populates it with boilerplate code based on its file extension

extension of `touch` command

## How to build

```bash
$ ./configure
```
```bash
$ make 
```

## Install
```bash
$ sudo make install
```

## Usage
pat a c,go file
```bash
$ pat main.c main.go
```
overpat(overwrite) files
```bash
$ pat -o main.c
```
pat a cat
```bash
$ pat index.html
```
```
$ cat index.html
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Document</title>
</head>
<body>

</body>
</html>
```
<sup>ok we are patting then catting</sup>


### Why pat?
pat is a saviour for lazy programmers, saving them from the agony of writing tiniest bit of code!
