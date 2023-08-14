#include "utility.h"

static pANTLR3_INPUT_STREAM input;
static phythonLexer lex;
static pANTLR3_COMMON_TOKEN_STREAM tokens;
static phythonParser parser;

ASTree getASTree(int argc, char *argv[]) {
    return ASTree(buildAntlrTree(argc, argv));
}

pANTLR3_BASE_TREE buildAntlrTree(int argc, char *argv[]) {
  
    assert(argc > 1);
    input = antlr3FileStreamNew((pANTLR3_UINT8)argv[1],ANTLR3_ENC_8BIT);
    lex = hythonLexerNew(input);
    tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT,
                                            TOKENSOURCE(lex));
    parser = hythonParserNew(tokens);
    hythonParser_prog_return r = parser->prog(parser);

    return r.tree;
}

void destoryAntlrTree() {
    parser->free(parser);
    tokens->free(tokens);
    lex->free(lex);
    input->close(input);
    return ;
}

