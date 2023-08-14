#include <utility.h>
#include <haizei_tree.h>

pANTLR3_INPUT_STREAM input;
pdemoLexer lex;
pANTLR3_COMMON_TOKEN_STREAM tokens;
pdemoParser parser;

ASTree fromFileBuildASTree(int argc, char *argv[]) {
    assert(argc > 1);
    input = antlr3FileStreamNew((pANTLR3_UINT8)argv[1], ANTLR3_ENC_8BIT);
    lex = demoLexerNew(input);
    tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
    parser = demoParserNew(tokens);
    demoParser_prog_return r = parser->prog(parser);
    return ASTree(r.tree);
}

void destroyASTree() {
    parser->free(parser);
    tokens->free(tokens);
    lex->free(lex);
    input->close(input);
    return ;
}

pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE tree, unsigned i) {
    assert(i < tree->getChildCount(tree));
    return (pANTLR3_BASE_TREE) tree->getChild(tree, i);
}

const char* getText(pANTLR3_BASE_TREE tree) {
    return (const char*) tree->getText(tree)->chars;
}
