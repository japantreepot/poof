
function counted_string
ToString(c_token_type Type)
{
  counted_string Result = {};
  switch (Type)
  {
    case CTokenType_Unknown: { Result = CS("CTokenType_Unknown"); } break;
    case CTokenType_CommentSingleLine: { Result = CS("CTokenType_CommentSingleLine"); } break;
    case CTokenType_CommentMultiLineStart: { Result = CS("CTokenType_CommentMultiLineStart"); } break;
    case CTokenType_CommentMultiLineEnd: { Result = CS("CTokenType_CommentMultiLineEnd"); } break;
    case CTokenType_Identifier: { Result = CS("CTokenType_Identifier"); } break;
    case CTokenType_String: { Result = CS("CTokenType_String"); } break;
    case CTokenType_Char: { Result = CS("CTokenType_Char"); } break;
    case CTokenType_OpenBracket: { Result = CS("CTokenType_OpenBracket"); } break;
    case CTokenType_CloseBracket: { Result = CS("CTokenType_CloseBracket"); } break;
    case CTokenType_OpenBrace: { Result = CS("CTokenType_OpenBrace"); } break;
    case CTokenType_CloseBrace: { Result = CS("CTokenType_CloseBrace"); } break;
    case CTokenType_OpenParen: { Result = CS("CTokenType_OpenParen"); } break;
    case CTokenType_CloseParen: { Result = CS("CTokenType_CloseParen"); } break;
    case CTokenType_Dot: { Result = CS("CTokenType_Dot"); } break;
    case CTokenType_Comma: { Result = CS("CTokenType_Comma"); } break;
    case CTokenType_Semicolon: { Result = CS("CTokenType_Semicolon"); } break;
    case CTokenType_Colon: { Result = CS("CTokenType_Colon"); } break;
    case CTokenType_Hash: { Result = CS("CTokenType_Hash"); } break;
    case CTokenType_At: { Result = CS("CTokenType_At"); } break;
    case CTokenType_Space: { Result = CS("CTokenType_Space"); } break;
    case CTokenType_Star: { Result = CS("CTokenType_Star"); } break;
    case CTokenType_Ampersand: { Result = CS("CTokenType_Ampersand"); } break;
    case CTokenType_SingleQuote: { Result = CS("CTokenType_SingleQuote"); } break;
    case CTokenType_DoubleQuote: { Result = CS("CTokenType_DoubleQuote"); } break;
    case CTokenType_Equals: { Result = CS("CTokenType_Equals"); } break;
    case CTokenType_LT: { Result = CS("CTokenType_LT"); } break;
    case CTokenType_GT: { Result = CS("CTokenType_GT"); } break;
    case CTokenType_Plus: { Result = CS("CTokenType_Plus"); } break;
    case CTokenType_Minus: { Result = CS("CTokenType_Minus"); } break;
    case CTokenType_Percent: { Result = CS("CTokenType_Percent"); } break;
    case CTokenType_Bang: { Result = CS("CTokenType_Bang"); } break;
    case CTokenType_Hat: { Result = CS("CTokenType_Hat"); } break;
    case CTokenType_Question: { Result = CS("CTokenType_Question"); } break;
    case CTokenType_FSlash: { Result = CS("CTokenType_FSlash"); } break;
    case CTokenType_BSlash: { Result = CS("CTokenType_BSlash"); } break;
    case CTokenType_Tilde: { Result = CS("CTokenType_Tilde"); } break;
    case CTokenType_Backtick: { Result = CS("CTokenType_Backtick"); } break;
    case CTokenType_Pipe: { Result = CS("CTokenType_Pipe"); } break;
    case CTokenType_Newline: { Result = CS("CTokenType_Newline"); } break;
    case CTokenType_CarrigeReturn: { Result = CS("CTokenType_CarrigeReturn"); } break;
    case CTokenType_EOF: { Result = CS("CTokenType_EOF"); } break;
  }
  return Result;
}

