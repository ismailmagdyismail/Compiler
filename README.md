# Compiler
* A compiler written in C++ (guided By wiritng an interpreter in  GO)
 
## Components 
* Lexer:
  - create tokens based on input file / string of text (NEVER fails , always returns tokens)

* Parser:
 - take tokens created by lexer and create AST with those tokens based on statement being parsed

* AST
 - tree nodes structure that gets created by parser 
