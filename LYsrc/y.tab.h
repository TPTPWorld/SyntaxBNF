#define AMPERSAND 257
#define AT_AT_SIGN_MINUS 258
#define AT_AT_SIGN_PLUS 259
#define AT_SIGN 260
#define AT_SIGN_EQUALS 261
#define AT_SIGN_MINUS 262
#define AT_SIGN_PLUS 263
#define CARET 264
#define COLON 265
#define COLON_EQUALS 266
#define COMMA 267
#define EQUALS 268
#define EQUALS_EQUALS 269
#define EQUALS_GREATER 270
#define EXCLAMATION 271
#define EXCLAMATION_EQUALS 272
#define EXCLAMATION_EXCLAMATION 273
#define EXCLAMATION_GREATER 274
#define LBRACE 275
#define LBRKT 276
#define LESS_EQUALS 277
#define LESS_EQUALS_GREATER 278
#define LESS_LESS 279
#define LESS_TILDE_GREATER 280
#define LPAREN 281
#define MINUS_MINUS_GREATER 282
#define PERIOD 283
#define QUESTION 284
#define QUESTION_QUESTION 285
#define QUESTION_STAR 286
#define RBRACE 287
#define RBRKT 288
#define RPAREN 289
#define STAR 290
#define TILDE 291
#define TILDE_AMPERSAND 292
#define TILDE_VLINE 293
#define VLINE 294
#define _DLR_cnf 295
#define _DLR_fof 296
#define _DLR_fot 297
#define _DLR_ite 298
#define _DLR_let 299
#define _DLR_tff 300
#define _DLR_thf 301
#define _LIT_cnf 302
#define _LIT_fof 303
#define _LIT_include 304
#define _LIT_tcf 305
#define _LIT_tff 306
#define _LIT_thf 307
#define _LIT_tpi 308
#define arrow 309
#define decimal 310
#define decimal_exponent 311
#define decimal_fraction 312
#define distinct_object 313
#define dollar_dollar_word 314
#define dollar_word 315
#define dot_decimal 316
#define exp_integer 317
#define hash 318
#define integer 319
#define less_sign 320
#define lower_word 321
#define plus 322
#define positive_decimal 323
#define rational 324
#define real 325
#define signed_exp_integer 326
#define signed_integer 327
#define signed_rational 328
#define signed_real 329
#define single_quoted 330
#define slash 331
#define slosh 332
#define star 333
#define unrecognized 334
#define unsigned_exp_integer 335
#define unsigned_integer 336
#define unsigned_rational 337
#define unsigned_real 338
#define upper_word 339
#define vline 340
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {int ival; double dval; char* sval; void* pval;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
