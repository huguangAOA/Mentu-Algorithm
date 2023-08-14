grammar demo;

options {
    language = C;
    output = AST;
    ASTLabelType=pANTLR3_BASE_TREE;
}

@header{
    #include <assert.h>
}

// The suffix '^' means make it a root.
// The suffix '!' means ignore it.

expr: multExpr ((PLUS^ | MINUS^) multExpr)*
    ;
 
PLUS: '+';
MINUS: '-';
multExpr 
    : atom (TIMES^ atom)*
    ;

TIMES: '*';

atom: INT
    | ID
    | '('! expr ')'!
    ;

stmt: expr NEWLINE -> expr  // tree rewrite syntax
    | ID ASSIGN expr NEWLINE -> ^(ASSIGN ID expr) // tree notation
    | NEWLINE ->   // ignore
    ;

ASSIGN: '=';

prog
    : (stmt {
            pANTLR3_STRING s = $stmt.tree->toStringTree($stmt.tree);
            assert(s->chars);
            printf(" tree \%s\n", s->chars);
        })+
    ;

ID: ('a'..'z'|'A'..'Z')+ ;
INT: '~'? '0'..'9'+ ;
NEWLINE: '\r'? '\n' ;
WS : (' '|'\t')+ {$channel = HIDDEN;};
