CREATE SCHEMA bdfaculdade;

USE bdfaculdade;

CREATE TABLE campus (
	id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
	cidade VARCHAR(20) NOT NULL,
	estado VARCHAR(2) NOT NULL
);

CREATE TABLE departamento (
	id INT PRIMARY KEY,
	nome_departamento VARCHAR(50) NOT NULL
);

CREATE TABLE curso (
	id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
	id_campus INT NOT NULL,
	id_departamento INT NOT NULL,
	nome_curso VARCHAR(30) NOT NULL,
	tipo_curso VARCHAR(14) NOT NULL,
	duracao VARCHAR(20) NOT NULL,
	FOREIGN KEY (id_campus) REFERENCES campus(id),
	FOREIGN KEY (id_departamento) REFERENCES departamento(id)
);

CREATE TABLE turma (
	id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
	id_curso INT NOT NULL,
	quantidade_Alunos INT NULL,
	data_fim DATE NOT NULL,
	data_inicio DATE NOT NULL,
	periodo VARCHAR(11) NOT NULL,
	FOREIGN KEY (id_curso) REFERENCES curso(id)
);

CREATE TABLE aluno (
	ra INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
	id_curso INT NOT NULL,
	id_campus INT NOT NULL,
	id_turma INT NOT NULL,
	nome VARCHAR(50) NOT NULL,
	cpf VARCHAR(14) UNIQUE NOT NULL,
	email VARCHAR(50) UNIQUE NULL,
	telefone VARCHAR(15) NOT NULL,
	celular VARCHAR(15) NULL,
	rua VARCHAR(100) NOT NULL,
	numero INT(5) NOT NULL,
	cep INT(8) NOT NULL,
	data_admissao DATE NOT NULL,
	FOREIGN KEY (id_curso) REFERENCES curso(id),
	FOREIGN KEY (id_campus) REFERENCES campus(id),
	FOREIGN KEY (id_turma) REFERENCES turma(id)
);

CREATE TABLE professor (
	id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
	id_departamento INT NOT NULL,
	nome VARCHAR(50) NOT NULL,
	cpf VARCHAR(14) UNIQUE NOT NULL,
	titulo VARCHAR(30) NULL,
	email_corporativo VARCHAR(50) UNIQUE NOT NULL,
	FOREIGN KEY (id_departamento) REFERENCES departamento(id)
);

CREATE TABLE disciplina (
	id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
	id_curso INT NOT NULL,
	id_departamento INT NOT NULL,
	id_professor INT NOT NULL,
	nome_disciplina VARCHAR(50) NOT NULL,
	descricao VARCHAR(120) NULL,
	FOREIGN KEY (id_curso) REFERENCES curso(id),
	FOREIGN KEY (id_departamento) REFERENCES departamento(id),
	FOREIGN KEY (id_professor) REFERENCES professor(id)
);

CREATE TABLE diario_classe (
	id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
	ra_aluno INT NOT NULL,
	id_disciplina INT NOT NULL,
	faltas INT(3) NULL,
	ae1 FLOAT(2,2) NULL,
	ae2 FLOAT(2,2) NULL,
	status VARCHAR(9) NULL,
	FOREIGN KEY (ra_aluno) REFERENCES aluno(ra),
	FOREIGN KEY (id_disciplina) REFERENCES disciplina(id)
);





