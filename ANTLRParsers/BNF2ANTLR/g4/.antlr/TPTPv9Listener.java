// Generated from /Users/daniel/Documents/coding_stuff/IDVDir/BNF2ANTLR/g4/TPTPv9.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link TPTPv9Parser}.
 */
public interface TPTPv9Listener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tptp_file}.
	 * @param ctx the parse tree
	 */
	void enterTptp_file(TPTPv9Parser.Tptp_fileContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tptp_file}.
	 * @param ctx the parse tree
	 */
	void exitTptp_file(TPTPv9Parser.Tptp_fileContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tptp_input}.
	 * @param ctx the parse tree
	 */
	void enterTptp_input(TPTPv9Parser.Tptp_inputContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tptp_input}.
	 * @param ctx the parse tree
	 */
	void exitTptp_input(TPTPv9Parser.Tptp_inputContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#annotated_formula}.
	 * @param ctx the parse tree
	 */
	void enterAnnotated_formula(TPTPv9Parser.Annotated_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#annotated_formula}.
	 * @param ctx the parse tree
	 */
	void exitAnnotated_formula(TPTPv9Parser.Annotated_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tpi_annotated}.
	 * @param ctx the parse tree
	 */
	void enterTpi_annotated(TPTPv9Parser.Tpi_annotatedContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tpi_annotated}.
	 * @param ctx the parse tree
	 */
	void exitTpi_annotated(TPTPv9Parser.Tpi_annotatedContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tpi_formula}.
	 * @param ctx the parse tree
	 */
	void enterTpi_formula(TPTPv9Parser.Tpi_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tpi_formula}.
	 * @param ctx the parse tree
	 */
	void exitTpi_formula(TPTPv9Parser.Tpi_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_annotated}.
	 * @param ctx the parse tree
	 */
	void enterThf_annotated(TPTPv9Parser.Thf_annotatedContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_annotated}.
	 * @param ctx the parse tree
	 */
	void exitThf_annotated(TPTPv9Parser.Thf_annotatedContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_annotated}.
	 * @param ctx the parse tree
	 */
	void enterTff_annotated(TPTPv9Parser.Tff_annotatedContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_annotated}.
	 * @param ctx the parse tree
	 */
	void exitTff_annotated(TPTPv9Parser.Tff_annotatedContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tcf_annotated}.
	 * @param ctx the parse tree
	 */
	void enterTcf_annotated(TPTPv9Parser.Tcf_annotatedContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tcf_annotated}.
	 * @param ctx the parse tree
	 */
	void exitTcf_annotated(TPTPv9Parser.Tcf_annotatedContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_annotated}.
	 * @param ctx the parse tree
	 */
	void enterFof_annotated(TPTPv9Parser.Fof_annotatedContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_annotated}.
	 * @param ctx the parse tree
	 */
	void exitFof_annotated(TPTPv9Parser.Fof_annotatedContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#cnf_annotated}.
	 * @param ctx the parse tree
	 */
	void enterCnf_annotated(TPTPv9Parser.Cnf_annotatedContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#cnf_annotated}.
	 * @param ctx the parse tree
	 */
	void exitCnf_annotated(TPTPv9Parser.Cnf_annotatedContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#annotations}.
	 * @param ctx the parse tree
	 */
	void enterAnnotations(TPTPv9Parser.AnnotationsContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#annotations}.
	 * @param ctx the parse tree
	 */
	void exitAnnotations(TPTPv9Parser.AnnotationsContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#formula_role}.
	 * @param ctx the parse tree
	 */
	void enterFormula_role(TPTPv9Parser.Formula_roleContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#formula_role}.
	 * @param ctx the parse tree
	 */
	void exitFormula_role(TPTPv9Parser.Formula_roleContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_formula}.
	 * @param ctx the parse tree
	 */
	void enterThf_formula(TPTPv9Parser.Thf_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_formula}.
	 * @param ctx the parse tree
	 */
	void exitThf_formula(TPTPv9Parser.Thf_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_logic_formula}.
	 * @param ctx the parse tree
	 */
	void enterThf_logic_formula(TPTPv9Parser.Thf_logic_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_logic_formula}.
	 * @param ctx the parse tree
	 */
	void exitThf_logic_formula(TPTPv9Parser.Thf_logic_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_binary_formula}.
	 * @param ctx the parse tree
	 */
	void enterThf_binary_formula(TPTPv9Parser.Thf_binary_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_binary_formula}.
	 * @param ctx the parse tree
	 */
	void exitThf_binary_formula(TPTPv9Parser.Thf_binary_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_binary_nonassoc}.
	 * @param ctx the parse tree
	 */
	void enterThf_binary_nonassoc(TPTPv9Parser.Thf_binary_nonassocContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_binary_nonassoc}.
	 * @param ctx the parse tree
	 */
	void exitThf_binary_nonassoc(TPTPv9Parser.Thf_binary_nonassocContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_binary_assoc}.
	 * @param ctx the parse tree
	 */
	void enterThf_binary_assoc(TPTPv9Parser.Thf_binary_assocContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_binary_assoc}.
	 * @param ctx the parse tree
	 */
	void exitThf_binary_assoc(TPTPv9Parser.Thf_binary_assocContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_or_formula}.
	 * @param ctx the parse tree
	 */
	void enterThf_or_formula(TPTPv9Parser.Thf_or_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_or_formula}.
	 * @param ctx the parse tree
	 */
	void exitThf_or_formula(TPTPv9Parser.Thf_or_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_and_formula}.
	 * @param ctx the parse tree
	 */
	void enterThf_and_formula(TPTPv9Parser.Thf_and_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_and_formula}.
	 * @param ctx the parse tree
	 */
	void exitThf_and_formula(TPTPv9Parser.Thf_and_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_apply_formula}.
	 * @param ctx the parse tree
	 */
	void enterThf_apply_formula(TPTPv9Parser.Thf_apply_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_apply_formula}.
	 * @param ctx the parse tree
	 */
	void exitThf_apply_formula(TPTPv9Parser.Thf_apply_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_unit_formula}.
	 * @param ctx the parse tree
	 */
	void enterThf_unit_formula(TPTPv9Parser.Thf_unit_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_unit_formula}.
	 * @param ctx the parse tree
	 */
	void exitThf_unit_formula(TPTPv9Parser.Thf_unit_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_preunit_formula}.
	 * @param ctx the parse tree
	 */
	void enterThf_preunit_formula(TPTPv9Parser.Thf_preunit_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_preunit_formula}.
	 * @param ctx the parse tree
	 */
	void exitThf_preunit_formula(TPTPv9Parser.Thf_preunit_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_unitary_formula}.
	 * @param ctx the parse tree
	 */
	void enterThf_unitary_formula(TPTPv9Parser.Thf_unitary_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_unitary_formula}.
	 * @param ctx the parse tree
	 */
	void exitThf_unitary_formula(TPTPv9Parser.Thf_unitary_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_quantified_formula}.
	 * @param ctx the parse tree
	 */
	void enterThf_quantified_formula(TPTPv9Parser.Thf_quantified_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_quantified_formula}.
	 * @param ctx the parse tree
	 */
	void exitThf_quantified_formula(TPTPv9Parser.Thf_quantified_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_quantification}.
	 * @param ctx the parse tree
	 */
	void enterThf_quantification(TPTPv9Parser.Thf_quantificationContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_quantification}.
	 * @param ctx the parse tree
	 */
	void exitThf_quantification(TPTPv9Parser.Thf_quantificationContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_variable_list}.
	 * @param ctx the parse tree
	 */
	void enterThf_variable_list(TPTPv9Parser.Thf_variable_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_variable_list}.
	 * @param ctx the parse tree
	 */
	void exitThf_variable_list(TPTPv9Parser.Thf_variable_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_typed_variable}.
	 * @param ctx the parse tree
	 */
	void enterThf_typed_variable(TPTPv9Parser.Thf_typed_variableContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_typed_variable}.
	 * @param ctx the parse tree
	 */
	void exitThf_typed_variable(TPTPv9Parser.Thf_typed_variableContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_unary_formula}.
	 * @param ctx the parse tree
	 */
	void enterThf_unary_formula(TPTPv9Parser.Thf_unary_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_unary_formula}.
	 * @param ctx the parse tree
	 */
	void exitThf_unary_formula(TPTPv9Parser.Thf_unary_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_prefix_unary}.
	 * @param ctx the parse tree
	 */
	void enterThf_prefix_unary(TPTPv9Parser.Thf_prefix_unaryContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_prefix_unary}.
	 * @param ctx the parse tree
	 */
	void exitThf_prefix_unary(TPTPv9Parser.Thf_prefix_unaryContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_infix_unary}.
	 * @param ctx the parse tree
	 */
	void enterThf_infix_unary(TPTPv9Parser.Thf_infix_unaryContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_infix_unary}.
	 * @param ctx the parse tree
	 */
	void exitThf_infix_unary(TPTPv9Parser.Thf_infix_unaryContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_atomic_formula}.
	 * @param ctx the parse tree
	 */
	void enterThf_atomic_formula(TPTPv9Parser.Thf_atomic_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_atomic_formula}.
	 * @param ctx the parse tree
	 */
	void exitThf_atomic_formula(TPTPv9Parser.Thf_atomic_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_plain_atomic}.
	 * @param ctx the parse tree
	 */
	void enterThf_plain_atomic(TPTPv9Parser.Thf_plain_atomicContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_plain_atomic}.
	 * @param ctx the parse tree
	 */
	void exitThf_plain_atomic(TPTPv9Parser.Thf_plain_atomicContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_defined_atomic}.
	 * @param ctx the parse tree
	 */
	void enterThf_defined_atomic(TPTPv9Parser.Thf_defined_atomicContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_defined_atomic}.
	 * @param ctx the parse tree
	 */
	void exitThf_defined_atomic(TPTPv9Parser.Thf_defined_atomicContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_defined_term}.
	 * @param ctx the parse tree
	 */
	void enterThf_defined_term(TPTPv9Parser.Thf_defined_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_defined_term}.
	 * @param ctx the parse tree
	 */
	void exitThf_defined_term(TPTPv9Parser.Thf_defined_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_defined_infix}.
	 * @param ctx the parse tree
	 */
	void enterThf_defined_infix(TPTPv9Parser.Thf_defined_infixContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_defined_infix}.
	 * @param ctx the parse tree
	 */
	void exitThf_defined_infix(TPTPv9Parser.Thf_defined_infixContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_system_atomic}.
	 * @param ctx the parse tree
	 */
	void enterThf_system_atomic(TPTPv9Parser.Thf_system_atomicContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_system_atomic}.
	 * @param ctx the parse tree
	 */
	void exitThf_system_atomic(TPTPv9Parser.Thf_system_atomicContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_let}.
	 * @param ctx the parse tree
	 */
	void enterThf_let(TPTPv9Parser.Thf_letContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_let}.
	 * @param ctx the parse tree
	 */
	void exitThf_let(TPTPv9Parser.Thf_letContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_let_types}.
	 * @param ctx the parse tree
	 */
	void enterThf_let_types(TPTPv9Parser.Thf_let_typesContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_let_types}.
	 * @param ctx the parse tree
	 */
	void exitThf_let_types(TPTPv9Parser.Thf_let_typesContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_atom_typing_list}.
	 * @param ctx the parse tree
	 */
	void enterThf_atom_typing_list(TPTPv9Parser.Thf_atom_typing_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_atom_typing_list}.
	 * @param ctx the parse tree
	 */
	void exitThf_atom_typing_list(TPTPv9Parser.Thf_atom_typing_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_let_defns}.
	 * @param ctx the parse tree
	 */
	void enterThf_let_defns(TPTPv9Parser.Thf_let_defnsContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_let_defns}.
	 * @param ctx the parse tree
	 */
	void exitThf_let_defns(TPTPv9Parser.Thf_let_defnsContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_let_defn}.
	 * @param ctx the parse tree
	 */
	void enterThf_let_defn(TPTPv9Parser.Thf_let_defnContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_let_defn}.
	 * @param ctx the parse tree
	 */
	void exitThf_let_defn(TPTPv9Parser.Thf_let_defnContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_let_defn_list}.
	 * @param ctx the parse tree
	 */
	void enterThf_let_defn_list(TPTPv9Parser.Thf_let_defn_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_let_defn_list}.
	 * @param ctx the parse tree
	 */
	void exitThf_let_defn_list(TPTPv9Parser.Thf_let_defn_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_unitary_term}.
	 * @param ctx the parse tree
	 */
	void enterThf_unitary_term(TPTPv9Parser.Thf_unitary_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_unitary_term}.
	 * @param ctx the parse tree
	 */
	void exitThf_unitary_term(TPTPv9Parser.Thf_unitary_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_conn_term}.
	 * @param ctx the parse tree
	 */
	void enterThf_conn_term(TPTPv9Parser.Thf_conn_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_conn_term}.
	 * @param ctx the parse tree
	 */
	void exitThf_conn_term(TPTPv9Parser.Thf_conn_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_tuple}.
	 * @param ctx the parse tree
	 */
	void enterThf_tuple(TPTPv9Parser.Thf_tupleContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_tuple}.
	 * @param ctx the parse tree
	 */
	void exitThf_tuple(TPTPv9Parser.Thf_tupleContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_fof_function}.
	 * @param ctx the parse tree
	 */
	void enterThf_fof_function(TPTPv9Parser.Thf_fof_functionContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_fof_function}.
	 * @param ctx the parse tree
	 */
	void exitThf_fof_function(TPTPv9Parser.Thf_fof_functionContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_arguments}.
	 * @param ctx the parse tree
	 */
	void enterThf_arguments(TPTPv9Parser.Thf_argumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_arguments}.
	 * @param ctx the parse tree
	 */
	void exitThf_arguments(TPTPv9Parser.Thf_argumentsContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_formula_list}.
	 * @param ctx the parse tree
	 */
	void enterThf_formula_list(TPTPv9Parser.Thf_formula_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_formula_list}.
	 * @param ctx the parse tree
	 */
	void exitThf_formula_list(TPTPv9Parser.Thf_formula_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_atom_typing}.
	 * @param ctx the parse tree
	 */
	void enterThf_atom_typing(TPTPv9Parser.Thf_atom_typingContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_atom_typing}.
	 * @param ctx the parse tree
	 */
	void exitThf_atom_typing(TPTPv9Parser.Thf_atom_typingContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_top_level_type}.
	 * @param ctx the parse tree
	 */
	void enterThf_top_level_type(TPTPv9Parser.Thf_top_level_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_top_level_type}.
	 * @param ctx the parse tree
	 */
	void exitThf_top_level_type(TPTPv9Parser.Thf_top_level_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_unitary_type}.
	 * @param ctx the parse tree
	 */
	void enterThf_unitary_type(TPTPv9Parser.Thf_unitary_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_unitary_type}.
	 * @param ctx the parse tree
	 */
	void exitThf_unitary_type(TPTPv9Parser.Thf_unitary_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_apply_type}.
	 * @param ctx the parse tree
	 */
	void enterThf_apply_type(TPTPv9Parser.Thf_apply_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_apply_type}.
	 * @param ctx the parse tree
	 */
	void exitThf_apply_type(TPTPv9Parser.Thf_apply_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_binary_type}.
	 * @param ctx the parse tree
	 */
	void enterThf_binary_type(TPTPv9Parser.Thf_binary_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_binary_type}.
	 * @param ctx the parse tree
	 */
	void exitThf_binary_type(TPTPv9Parser.Thf_binary_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_mapping_type}.
	 * @param ctx the parse tree
	 */
	void enterThf_mapping_type(TPTPv9Parser.Thf_mapping_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_mapping_type}.
	 * @param ctx the parse tree
	 */
	void exitThf_mapping_type(TPTPv9Parser.Thf_mapping_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_xprod_type}.
	 * @param ctx the parse tree
	 */
	void enterThf_xprod_type(TPTPv9Parser.Thf_xprod_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_xprod_type}.
	 * @param ctx the parse tree
	 */
	void exitThf_xprod_type(TPTPv9Parser.Thf_xprod_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_union_type}.
	 * @param ctx the parse tree
	 */
	void enterThf_union_type(TPTPv9Parser.Thf_union_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_union_type}.
	 * @param ctx the parse tree
	 */
	void exitThf_union_type(TPTPv9Parser.Thf_union_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_subtype}.
	 * @param ctx the parse tree
	 */
	void enterThf_subtype(TPTPv9Parser.Thf_subtypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_subtype}.
	 * @param ctx the parse tree
	 */
	void exitThf_subtype(TPTPv9Parser.Thf_subtypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_definition}.
	 * @param ctx the parse tree
	 */
	void enterThf_definition(TPTPv9Parser.Thf_definitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_definition}.
	 * @param ctx the parse tree
	 */
	void exitThf_definition(TPTPv9Parser.Thf_definitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_sequent}.
	 * @param ctx the parse tree
	 */
	void enterThf_sequent(TPTPv9Parser.Thf_sequentContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_sequent}.
	 * @param ctx the parse tree
	 */
	void exitThf_sequent(TPTPv9Parser.Thf_sequentContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_formula}.
	 * @param ctx the parse tree
	 */
	void enterTff_formula(TPTPv9Parser.Tff_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_formula}.
	 * @param ctx the parse tree
	 */
	void exitTff_formula(TPTPv9Parser.Tff_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_logic_formula}.
	 * @param ctx the parse tree
	 */
	void enterTff_logic_formula(TPTPv9Parser.Tff_logic_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_logic_formula}.
	 * @param ctx the parse tree
	 */
	void exitTff_logic_formula(TPTPv9Parser.Tff_logic_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_binary_formula}.
	 * @param ctx the parse tree
	 */
	void enterTff_binary_formula(TPTPv9Parser.Tff_binary_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_binary_formula}.
	 * @param ctx the parse tree
	 */
	void exitTff_binary_formula(TPTPv9Parser.Tff_binary_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_binary_nonassoc}.
	 * @param ctx the parse tree
	 */
	void enterTff_binary_nonassoc(TPTPv9Parser.Tff_binary_nonassocContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_binary_nonassoc}.
	 * @param ctx the parse tree
	 */
	void exitTff_binary_nonassoc(TPTPv9Parser.Tff_binary_nonassocContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_binary_assoc}.
	 * @param ctx the parse tree
	 */
	void enterTff_binary_assoc(TPTPv9Parser.Tff_binary_assocContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_binary_assoc}.
	 * @param ctx the parse tree
	 */
	void exitTff_binary_assoc(TPTPv9Parser.Tff_binary_assocContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_or_formula}.
	 * @param ctx the parse tree
	 */
	void enterTff_or_formula(TPTPv9Parser.Tff_or_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_or_formula}.
	 * @param ctx the parse tree
	 */
	void exitTff_or_formula(TPTPv9Parser.Tff_or_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_and_formula}.
	 * @param ctx the parse tree
	 */
	void enterTff_and_formula(TPTPv9Parser.Tff_and_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_and_formula}.
	 * @param ctx the parse tree
	 */
	void exitTff_and_formula(TPTPv9Parser.Tff_and_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_unit_formula}.
	 * @param ctx the parse tree
	 */
	void enterTff_unit_formula(TPTPv9Parser.Tff_unit_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_unit_formula}.
	 * @param ctx the parse tree
	 */
	void exitTff_unit_formula(TPTPv9Parser.Tff_unit_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_preunit_formula}.
	 * @param ctx the parse tree
	 */
	void enterTff_preunit_formula(TPTPv9Parser.Tff_preunit_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_preunit_formula}.
	 * @param ctx the parse tree
	 */
	void exitTff_preunit_formula(TPTPv9Parser.Tff_preunit_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_unitary_formula}.
	 * @param ctx the parse tree
	 */
	void enterTff_unitary_formula(TPTPv9Parser.Tff_unitary_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_unitary_formula}.
	 * @param ctx the parse tree
	 */
	void exitTff_unitary_formula(TPTPv9Parser.Tff_unitary_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#txf_unitary_formula}.
	 * @param ctx the parse tree
	 */
	void enterTxf_unitary_formula(TPTPv9Parser.Txf_unitary_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#txf_unitary_formula}.
	 * @param ctx the parse tree
	 */
	void exitTxf_unitary_formula(TPTPv9Parser.Txf_unitary_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_quantified_formula}.
	 * @param ctx the parse tree
	 */
	void enterTff_quantified_formula(TPTPv9Parser.Tff_quantified_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_quantified_formula}.
	 * @param ctx the parse tree
	 */
	void exitTff_quantified_formula(TPTPv9Parser.Tff_quantified_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_variable_list}.
	 * @param ctx the parse tree
	 */
	void enterTff_variable_list(TPTPv9Parser.Tff_variable_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_variable_list}.
	 * @param ctx the parse tree
	 */
	void exitTff_variable_list(TPTPv9Parser.Tff_variable_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_variable}.
	 * @param ctx the parse tree
	 */
	void enterTff_variable(TPTPv9Parser.Tff_variableContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_variable}.
	 * @param ctx the parse tree
	 */
	void exitTff_variable(TPTPv9Parser.Tff_variableContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_typed_variable}.
	 * @param ctx the parse tree
	 */
	void enterTff_typed_variable(TPTPv9Parser.Tff_typed_variableContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_typed_variable}.
	 * @param ctx the parse tree
	 */
	void exitTff_typed_variable(TPTPv9Parser.Tff_typed_variableContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_unary_formula}.
	 * @param ctx the parse tree
	 */
	void enterTff_unary_formula(TPTPv9Parser.Tff_unary_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_unary_formula}.
	 * @param ctx the parse tree
	 */
	void exitTff_unary_formula(TPTPv9Parser.Tff_unary_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_prefix_unary}.
	 * @param ctx the parse tree
	 */
	void enterTff_prefix_unary(TPTPv9Parser.Tff_prefix_unaryContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_prefix_unary}.
	 * @param ctx the parse tree
	 */
	void exitTff_prefix_unary(TPTPv9Parser.Tff_prefix_unaryContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_infix_unary}.
	 * @param ctx the parse tree
	 */
	void enterTff_infix_unary(TPTPv9Parser.Tff_infix_unaryContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_infix_unary}.
	 * @param ctx the parse tree
	 */
	void exitTff_infix_unary(TPTPv9Parser.Tff_infix_unaryContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_atomic_formula}.
	 * @param ctx the parse tree
	 */
	void enterTff_atomic_formula(TPTPv9Parser.Tff_atomic_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_atomic_formula}.
	 * @param ctx the parse tree
	 */
	void exitTff_atomic_formula(TPTPv9Parser.Tff_atomic_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_plain_atomic}.
	 * @param ctx the parse tree
	 */
	void enterTff_plain_atomic(TPTPv9Parser.Tff_plain_atomicContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_plain_atomic}.
	 * @param ctx the parse tree
	 */
	void exitTff_plain_atomic(TPTPv9Parser.Tff_plain_atomicContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_defined_atomic}.
	 * @param ctx the parse tree
	 */
	void enterTff_defined_atomic(TPTPv9Parser.Tff_defined_atomicContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_defined_atomic}.
	 * @param ctx the parse tree
	 */
	void exitTff_defined_atomic(TPTPv9Parser.Tff_defined_atomicContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_defined_plain}.
	 * @param ctx the parse tree
	 */
	void enterTff_defined_plain(TPTPv9Parser.Tff_defined_plainContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_defined_plain}.
	 * @param ctx the parse tree
	 */
	void exitTff_defined_plain(TPTPv9Parser.Tff_defined_plainContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_defined_infix}.
	 * @param ctx the parse tree
	 */
	void enterTff_defined_infix(TPTPv9Parser.Tff_defined_infixContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_defined_infix}.
	 * @param ctx the parse tree
	 */
	void exitTff_defined_infix(TPTPv9Parser.Tff_defined_infixContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_system_atomic}.
	 * @param ctx the parse tree
	 */
	void enterTff_system_atomic(TPTPv9Parser.Tff_system_atomicContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_system_atomic}.
	 * @param ctx the parse tree
	 */
	void exitTff_system_atomic(TPTPv9Parser.Tff_system_atomicContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#txf_let}.
	 * @param ctx the parse tree
	 */
	void enterTxf_let(TPTPv9Parser.Txf_letContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#txf_let}.
	 * @param ctx the parse tree
	 */
	void exitTxf_let(TPTPv9Parser.Txf_letContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#txf_let_types}.
	 * @param ctx the parse tree
	 */
	void enterTxf_let_types(TPTPv9Parser.Txf_let_typesContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#txf_let_types}.
	 * @param ctx the parse tree
	 */
	void exitTxf_let_types(TPTPv9Parser.Txf_let_typesContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_atom_typing_list}.
	 * @param ctx the parse tree
	 */
	void enterTff_atom_typing_list(TPTPv9Parser.Tff_atom_typing_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_atom_typing_list}.
	 * @param ctx the parse tree
	 */
	void exitTff_atom_typing_list(TPTPv9Parser.Tff_atom_typing_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#txf_let_defns}.
	 * @param ctx the parse tree
	 */
	void enterTxf_let_defns(TPTPv9Parser.Txf_let_defnsContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#txf_let_defns}.
	 * @param ctx the parse tree
	 */
	void exitTxf_let_defns(TPTPv9Parser.Txf_let_defnsContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#txf_let_defn}.
	 * @param ctx the parse tree
	 */
	void enterTxf_let_defn(TPTPv9Parser.Txf_let_defnContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#txf_let_defn}.
	 * @param ctx the parse tree
	 */
	void exitTxf_let_defn(TPTPv9Parser.Txf_let_defnContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#txf_let_LHS}.
	 * @param ctx the parse tree
	 */
	void enterTxf_let_LHS(TPTPv9Parser.Txf_let_LHSContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#txf_let_LHS}.
	 * @param ctx the parse tree
	 */
	void exitTxf_let_LHS(TPTPv9Parser.Txf_let_LHSContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#txf_let_defn_list}.
	 * @param ctx the parse tree
	 */
	void enterTxf_let_defn_list(TPTPv9Parser.Txf_let_defn_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#txf_let_defn_list}.
	 * @param ctx the parse tree
	 */
	void exitTxf_let_defn_list(TPTPv9Parser.Txf_let_defn_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#nxf_atom}.
	 * @param ctx the parse tree
	 */
	void enterNxf_atom(TPTPv9Parser.Nxf_atomContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#nxf_atom}.
	 * @param ctx the parse tree
	 */
	void exitNxf_atom(TPTPv9Parser.Nxf_atomContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_term}.
	 * @param ctx the parse tree
	 */
	void enterTff_term(TPTPv9Parser.Tff_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_term}.
	 * @param ctx the parse tree
	 */
	void exitTff_term(TPTPv9Parser.Tff_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_unitary_term}.
	 * @param ctx the parse tree
	 */
	void enterTff_unitary_term(TPTPv9Parser.Tff_unitary_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_unitary_term}.
	 * @param ctx the parse tree
	 */
	void exitTff_unitary_term(TPTPv9Parser.Tff_unitary_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#txf_tuple}.
	 * @param ctx the parse tree
	 */
	void enterTxf_tuple(TPTPv9Parser.Txf_tupleContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#txf_tuple}.
	 * @param ctx the parse tree
	 */
	void exitTxf_tuple(TPTPv9Parser.Txf_tupleContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_arguments}.
	 * @param ctx the parse tree
	 */
	void enterTff_arguments(TPTPv9Parser.Tff_argumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_arguments}.
	 * @param ctx the parse tree
	 */
	void exitTff_arguments(TPTPv9Parser.Tff_argumentsContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_atom_typing}.
	 * @param ctx the parse tree
	 */
	void enterTff_atom_typing(TPTPv9Parser.Tff_atom_typingContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_atom_typing}.
	 * @param ctx the parse tree
	 */
	void exitTff_atom_typing(TPTPv9Parser.Tff_atom_typingContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_top_level_type}.
	 * @param ctx the parse tree
	 */
	void enterTff_top_level_type(TPTPv9Parser.Tff_top_level_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_top_level_type}.
	 * @param ctx the parse tree
	 */
	void exitTff_top_level_type(TPTPv9Parser.Tff_top_level_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_non_atomic_type}.
	 * @param ctx the parse tree
	 */
	void enterTff_non_atomic_type(TPTPv9Parser.Tff_non_atomic_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_non_atomic_type}.
	 * @param ctx the parse tree
	 */
	void exitTff_non_atomic_type(TPTPv9Parser.Tff_non_atomic_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tf1_quantified_type}.
	 * @param ctx the parse tree
	 */
	void enterTf1_quantified_type(TPTPv9Parser.Tf1_quantified_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tf1_quantified_type}.
	 * @param ctx the parse tree
	 */
	void exitTf1_quantified_type(TPTPv9Parser.Tf1_quantified_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_monotype}.
	 * @param ctx the parse tree
	 */
	void enterTff_monotype(TPTPv9Parser.Tff_monotypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_monotype}.
	 * @param ctx the parse tree
	 */
	void exitTff_monotype(TPTPv9Parser.Tff_monotypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_unitary_type}.
	 * @param ctx the parse tree
	 */
	void enterTff_unitary_type(TPTPv9Parser.Tff_unitary_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_unitary_type}.
	 * @param ctx the parse tree
	 */
	void exitTff_unitary_type(TPTPv9Parser.Tff_unitary_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_atomic_type}.
	 * @param ctx the parse tree
	 */
	void enterTff_atomic_type(TPTPv9Parser.Tff_atomic_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_atomic_type}.
	 * @param ctx the parse tree
	 */
	void exitTff_atomic_type(TPTPv9Parser.Tff_atomic_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_type_arguments}.
	 * @param ctx the parse tree
	 */
	void enterTff_type_arguments(TPTPv9Parser.Tff_type_argumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_type_arguments}.
	 * @param ctx the parse tree
	 */
	void exitTff_type_arguments(TPTPv9Parser.Tff_type_argumentsContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_mapping_type}.
	 * @param ctx the parse tree
	 */
	void enterTff_mapping_type(TPTPv9Parser.Tff_mapping_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_mapping_type}.
	 * @param ctx the parse tree
	 */
	void exitTff_mapping_type(TPTPv9Parser.Tff_mapping_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_xprod_type}.
	 * @param ctx the parse tree
	 */
	void enterTff_xprod_type(TPTPv9Parser.Tff_xprod_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_xprod_type}.
	 * @param ctx the parse tree
	 */
	void exitTff_xprod_type(TPTPv9Parser.Tff_xprod_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#txf_tuple_type}.
	 * @param ctx the parse tree
	 */
	void enterTxf_tuple_type(TPTPv9Parser.Txf_tuple_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#txf_tuple_type}.
	 * @param ctx the parse tree
	 */
	void exitTxf_tuple_type(TPTPv9Parser.Txf_tuple_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_type_list}.
	 * @param ctx the parse tree
	 */
	void enterTff_type_list(TPTPv9Parser.Tff_type_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_type_list}.
	 * @param ctx the parse tree
	 */
	void exitTff_type_list(TPTPv9Parser.Tff_type_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_subtype}.
	 * @param ctx the parse tree
	 */
	void enterTff_subtype(TPTPv9Parser.Tff_subtypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_subtype}.
	 * @param ctx the parse tree
	 */
	void exitTff_subtype(TPTPv9Parser.Tff_subtypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#txf_definition}.
	 * @param ctx the parse tree
	 */
	void enterTxf_definition(TPTPv9Parser.Txf_definitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#txf_definition}.
	 * @param ctx the parse tree
	 */
	void exitTxf_definition(TPTPv9Parser.Txf_definitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#txf_sequent}.
	 * @param ctx the parse tree
	 */
	void enterTxf_sequent(TPTPv9Parser.Txf_sequentContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#txf_sequent}.
	 * @param ctx the parse tree
	 */
	void exitTxf_sequent(TPTPv9Parser.Txf_sequentContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#nhf_long_connective}.
	 * @param ctx the parse tree
	 */
	void enterNhf_long_connective(TPTPv9Parser.Nhf_long_connectiveContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#nhf_long_connective}.
	 * @param ctx the parse tree
	 */
	void exitNhf_long_connective(TPTPv9Parser.Nhf_long_connectiveContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#nhf_parameter_list}.
	 * @param ctx the parse tree
	 */
	void enterNhf_parameter_list(TPTPv9Parser.Nhf_parameter_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#nhf_parameter_list}.
	 * @param ctx the parse tree
	 */
	void exitNhf_parameter_list(TPTPv9Parser.Nhf_parameter_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#nhf_parameter}.
	 * @param ctx the parse tree
	 */
	void enterNhf_parameter(TPTPv9Parser.Nhf_parameterContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#nhf_parameter}.
	 * @param ctx the parse tree
	 */
	void exitNhf_parameter(TPTPv9Parser.Nhf_parameterContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#nhf_key_pair}.
	 * @param ctx the parse tree
	 */
	void enterNhf_key_pair(TPTPv9Parser.Nhf_key_pairContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#nhf_key_pair}.
	 * @param ctx the parse tree
	 */
	void exitNhf_key_pair(TPTPv9Parser.Nhf_key_pairContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#nxf_long_connective}.
	 * @param ctx the parse tree
	 */
	void enterNxf_long_connective(TPTPv9Parser.Nxf_long_connectiveContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#nxf_long_connective}.
	 * @param ctx the parse tree
	 */
	void exitNxf_long_connective(TPTPv9Parser.Nxf_long_connectiveContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#nxf_parameter_list}.
	 * @param ctx the parse tree
	 */
	void enterNxf_parameter_list(TPTPv9Parser.Nxf_parameter_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#nxf_parameter_list}.
	 * @param ctx the parse tree
	 */
	void exitNxf_parameter_list(TPTPv9Parser.Nxf_parameter_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#nxf_parameter}.
	 * @param ctx the parse tree
	 */
	void enterNxf_parameter(TPTPv9Parser.Nxf_parameterContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#nxf_parameter}.
	 * @param ctx the parse tree
	 */
	void exitNxf_parameter(TPTPv9Parser.Nxf_parameterContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#nxf_key_pair}.
	 * @param ctx the parse tree
	 */
	void enterNxf_key_pair(TPTPv9Parser.Nxf_key_pairContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#nxf_key_pair}.
	 * @param ctx the parse tree
	 */
	void exitNxf_key_pair(TPTPv9Parser.Nxf_key_pairContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#ntf_connective_name}.
	 * @param ctx the parse tree
	 */
	void enterNtf_connective_name(TPTPv9Parser.Ntf_connective_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#ntf_connective_name}.
	 * @param ctx the parse tree
	 */
	void exitNtf_connective_name(TPTPv9Parser.Ntf_connective_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#ntf_index}.
	 * @param ctx the parse tree
	 */
	void enterNtf_index(TPTPv9Parser.Ntf_indexContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#ntf_index}.
	 * @param ctx the parse tree
	 */
	void exitNtf_index(TPTPv9Parser.Ntf_indexContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#ntf_short_connective}.
	 * @param ctx the parse tree
	 */
	void enterNtf_short_connective(TPTPv9Parser.Ntf_short_connectiveContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#ntf_short_connective}.
	 * @param ctx the parse tree
	 */
	void exitNtf_short_connective(TPTPv9Parser.Ntf_short_connectiveContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tcf_formula}.
	 * @param ctx the parse tree
	 */
	void enterTcf_formula(TPTPv9Parser.Tcf_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tcf_formula}.
	 * @param ctx the parse tree
	 */
	void exitTcf_formula(TPTPv9Parser.Tcf_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tcf_logic_formula}.
	 * @param ctx the parse tree
	 */
	void enterTcf_logic_formula(TPTPv9Parser.Tcf_logic_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tcf_logic_formula}.
	 * @param ctx the parse tree
	 */
	void exitTcf_logic_formula(TPTPv9Parser.Tcf_logic_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tcf_quantified_formula}.
	 * @param ctx the parse tree
	 */
	void enterTcf_quantified_formula(TPTPv9Parser.Tcf_quantified_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tcf_quantified_formula}.
	 * @param ctx the parse tree
	 */
	void exitTcf_quantified_formula(TPTPv9Parser.Tcf_quantified_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_formula(TPTPv9Parser.Fof_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_formula(TPTPv9Parser.Fof_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_logic_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_logic_formula(TPTPv9Parser.Fof_logic_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_logic_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_logic_formula(TPTPv9Parser.Fof_logic_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_binary_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_binary_formula(TPTPv9Parser.Fof_binary_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_binary_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_binary_formula(TPTPv9Parser.Fof_binary_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_binary_nonassoc}.
	 * @param ctx the parse tree
	 */
	void enterFof_binary_nonassoc(TPTPv9Parser.Fof_binary_nonassocContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_binary_nonassoc}.
	 * @param ctx the parse tree
	 */
	void exitFof_binary_nonassoc(TPTPv9Parser.Fof_binary_nonassocContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_binary_assoc}.
	 * @param ctx the parse tree
	 */
	void enterFof_binary_assoc(TPTPv9Parser.Fof_binary_assocContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_binary_assoc}.
	 * @param ctx the parse tree
	 */
	void exitFof_binary_assoc(TPTPv9Parser.Fof_binary_assocContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_or_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_or_formula(TPTPv9Parser.Fof_or_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_or_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_or_formula(TPTPv9Parser.Fof_or_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_and_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_and_formula(TPTPv9Parser.Fof_and_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_and_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_and_formula(TPTPv9Parser.Fof_and_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_unary_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_unary_formula(TPTPv9Parser.Fof_unary_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_unary_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_unary_formula(TPTPv9Parser.Fof_unary_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_infix_unary}.
	 * @param ctx the parse tree
	 */
	void enterFof_infix_unary(TPTPv9Parser.Fof_infix_unaryContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_infix_unary}.
	 * @param ctx the parse tree
	 */
	void exitFof_infix_unary(TPTPv9Parser.Fof_infix_unaryContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_unit_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_unit_formula(TPTPv9Parser.Fof_unit_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_unit_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_unit_formula(TPTPv9Parser.Fof_unit_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_unitary_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_unitary_formula(TPTPv9Parser.Fof_unitary_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_unitary_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_unitary_formula(TPTPv9Parser.Fof_unitary_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_quantified_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_quantified_formula(TPTPv9Parser.Fof_quantified_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_quantified_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_quantified_formula(TPTPv9Parser.Fof_quantified_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_variable_list}.
	 * @param ctx the parse tree
	 */
	void enterFof_variable_list(TPTPv9Parser.Fof_variable_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_variable_list}.
	 * @param ctx the parse tree
	 */
	void exitFof_variable_list(TPTPv9Parser.Fof_variable_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_atomic_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_atomic_formula(TPTPv9Parser.Fof_atomic_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_atomic_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_atomic_formula(TPTPv9Parser.Fof_atomic_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_plain_atomic_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_plain_atomic_formula(TPTPv9Parser.Fof_plain_atomic_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_plain_atomic_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_plain_atomic_formula(TPTPv9Parser.Fof_plain_atomic_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_defined_atomic_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_defined_atomic_formula(TPTPv9Parser.Fof_defined_atomic_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_defined_atomic_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_defined_atomic_formula(TPTPv9Parser.Fof_defined_atomic_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_defined_plain_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_defined_plain_formula(TPTPv9Parser.Fof_defined_plain_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_defined_plain_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_defined_plain_formula(TPTPv9Parser.Fof_defined_plain_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_defined_infix_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_defined_infix_formula(TPTPv9Parser.Fof_defined_infix_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_defined_infix_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_defined_infix_formula(TPTPv9Parser.Fof_defined_infix_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_system_atomic_formula}.
	 * @param ctx the parse tree
	 */
	void enterFof_system_atomic_formula(TPTPv9Parser.Fof_system_atomic_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_system_atomic_formula}.
	 * @param ctx the parse tree
	 */
	void exitFof_system_atomic_formula(TPTPv9Parser.Fof_system_atomic_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_plain_term}.
	 * @param ctx the parse tree
	 */
	void enterFof_plain_term(TPTPv9Parser.Fof_plain_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_plain_term}.
	 * @param ctx the parse tree
	 */
	void exitFof_plain_term(TPTPv9Parser.Fof_plain_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_defined_term}.
	 * @param ctx the parse tree
	 */
	void enterFof_defined_term(TPTPv9Parser.Fof_defined_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_defined_term}.
	 * @param ctx the parse tree
	 */
	void exitFof_defined_term(TPTPv9Parser.Fof_defined_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_defined_atomic_term}.
	 * @param ctx the parse tree
	 */
	void enterFof_defined_atomic_term(TPTPv9Parser.Fof_defined_atomic_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_defined_atomic_term}.
	 * @param ctx the parse tree
	 */
	void exitFof_defined_atomic_term(TPTPv9Parser.Fof_defined_atomic_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_defined_plain_term}.
	 * @param ctx the parse tree
	 */
	void enterFof_defined_plain_term(TPTPv9Parser.Fof_defined_plain_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_defined_plain_term}.
	 * @param ctx the parse tree
	 */
	void exitFof_defined_plain_term(TPTPv9Parser.Fof_defined_plain_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_system_term}.
	 * @param ctx the parse tree
	 */
	void enterFof_system_term(TPTPv9Parser.Fof_system_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_system_term}.
	 * @param ctx the parse tree
	 */
	void exitFof_system_term(TPTPv9Parser.Fof_system_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_arguments}.
	 * @param ctx the parse tree
	 */
	void enterFof_arguments(TPTPv9Parser.Fof_argumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_arguments}.
	 * @param ctx the parse tree
	 */
	void exitFof_arguments(TPTPv9Parser.Fof_argumentsContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_term}.
	 * @param ctx the parse tree
	 */
	void enterFof_term(TPTPv9Parser.Fof_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_term}.
	 * @param ctx the parse tree
	 */
	void exitFof_term(TPTPv9Parser.Fof_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_function_term}.
	 * @param ctx the parse tree
	 */
	void enterFof_function_term(TPTPv9Parser.Fof_function_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_function_term}.
	 * @param ctx the parse tree
	 */
	void exitFof_function_term(TPTPv9Parser.Fof_function_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_sequent}.
	 * @param ctx the parse tree
	 */
	void enterFof_sequent(TPTPv9Parser.Fof_sequentContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_sequent}.
	 * @param ctx the parse tree
	 */
	void exitFof_sequent(TPTPv9Parser.Fof_sequentContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_formula_tuple}.
	 * @param ctx the parse tree
	 */
	void enterFof_formula_tuple(TPTPv9Parser.Fof_formula_tupleContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_formula_tuple}.
	 * @param ctx the parse tree
	 */
	void exitFof_formula_tuple(TPTPv9Parser.Fof_formula_tupleContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_formula_tuple_list}.
	 * @param ctx the parse tree
	 */
	void enterFof_formula_tuple_list(TPTPv9Parser.Fof_formula_tuple_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_formula_tuple_list}.
	 * @param ctx the parse tree
	 */
	void exitFof_formula_tuple_list(TPTPv9Parser.Fof_formula_tuple_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#cnf_formula}.
	 * @param ctx the parse tree
	 */
	void enterCnf_formula(TPTPv9Parser.Cnf_formulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#cnf_formula}.
	 * @param ctx the parse tree
	 */
	void exitCnf_formula(TPTPv9Parser.Cnf_formulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#cnf_disjunction}.
	 * @param ctx the parse tree
	 */
	void enterCnf_disjunction(TPTPv9Parser.Cnf_disjunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#cnf_disjunction}.
	 * @param ctx the parse tree
	 */
	void exitCnf_disjunction(TPTPv9Parser.Cnf_disjunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#cnf_literal}.
	 * @param ctx the parse tree
	 */
	void enterCnf_literal(TPTPv9Parser.Cnf_literalContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#cnf_literal}.
	 * @param ctx the parse tree
	 */
	void exitCnf_literal(TPTPv9Parser.Cnf_literalContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_quantifier}.
	 * @param ctx the parse tree
	 */
	void enterThf_quantifier(TPTPv9Parser.Thf_quantifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_quantifier}.
	 * @param ctx the parse tree
	 */
	void exitThf_quantifier(TPTPv9Parser.Thf_quantifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#thf_unary_connective}.
	 * @param ctx the parse tree
	 */
	void enterThf_unary_connective(TPTPv9Parser.Thf_unary_connectiveContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#thf_unary_connective}.
	 * @param ctx the parse tree
	 */
	void exitThf_unary_connective(TPTPv9Parser.Thf_unary_connectiveContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#th1_quantifier}.
	 * @param ctx the parse tree
	 */
	void enterTh1_quantifier(TPTPv9Parser.Th1_quantifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#th1_quantifier}.
	 * @param ctx the parse tree
	 */
	void exitTh1_quantifier(TPTPv9Parser.Th1_quantifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#th0_quantifier}.
	 * @param ctx the parse tree
	 */
	void enterTh0_quantifier(TPTPv9Parser.Th0_quantifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#th0_quantifier}.
	 * @param ctx the parse tree
	 */
	void exitTh0_quantifier(TPTPv9Parser.Th0_quantifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#subtype_sign}.
	 * @param ctx the parse tree
	 */
	void enterSubtype_sign(TPTPv9Parser.Subtype_signContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#subtype_sign}.
	 * @param ctx the parse tree
	 */
	void exitSubtype_sign(TPTPv9Parser.Subtype_signContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_unary_connective}.
	 * @param ctx the parse tree
	 */
	void enterTff_unary_connective(TPTPv9Parser.Tff_unary_connectiveContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_unary_connective}.
	 * @param ctx the parse tree
	 */
	void exitTff_unary_connective(TPTPv9Parser.Tff_unary_connectiveContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#tff_quantifier}.
	 * @param ctx the parse tree
	 */
	void enterTff_quantifier(TPTPv9Parser.Tff_quantifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#tff_quantifier}.
	 * @param ctx the parse tree
	 */
	void exitTff_quantifier(TPTPv9Parser.Tff_quantifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#fof_quantifier}.
	 * @param ctx the parse tree
	 */
	void enterFof_quantifier(TPTPv9Parser.Fof_quantifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#fof_quantifier}.
	 * @param ctx the parse tree
	 */
	void exitFof_quantifier(TPTPv9Parser.Fof_quantifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#nonassoc_connective}.
	 * @param ctx the parse tree
	 */
	void enterNonassoc_connective(TPTPv9Parser.Nonassoc_connectiveContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#nonassoc_connective}.
	 * @param ctx the parse tree
	 */
	void exitNonassoc_connective(TPTPv9Parser.Nonassoc_connectiveContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#assoc_connective}.
	 * @param ctx the parse tree
	 */
	void enterAssoc_connective(TPTPv9Parser.Assoc_connectiveContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#assoc_connective}.
	 * @param ctx the parse tree
	 */
	void exitAssoc_connective(TPTPv9Parser.Assoc_connectiveContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#unary_connective}.
	 * @param ctx the parse tree
	 */
	void enterUnary_connective(TPTPv9Parser.Unary_connectiveContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#unary_connective}.
	 * @param ctx the parse tree
	 */
	void exitUnary_connective(TPTPv9Parser.Unary_connectiveContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#gentzen_arrow}.
	 * @param ctx the parse tree
	 */
	void enterGentzen_arrow(TPTPv9Parser.Gentzen_arrowContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#gentzen_arrow}.
	 * @param ctx the parse tree
	 */
	void exitGentzen_arrow(TPTPv9Parser.Gentzen_arrowContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#assignment}.
	 * @param ctx the parse tree
	 */
	void enterAssignment(TPTPv9Parser.AssignmentContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#assignment}.
	 * @param ctx the parse tree
	 */
	void exitAssignment(TPTPv9Parser.AssignmentContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#identical}.
	 * @param ctx the parse tree
	 */
	void enterIdentical(TPTPv9Parser.IdenticalContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#identical}.
	 * @param ctx the parse tree
	 */
	void exitIdentical(TPTPv9Parser.IdenticalContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#type_constant}.
	 * @param ctx the parse tree
	 */
	void enterType_constant(TPTPv9Parser.Type_constantContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#type_constant}.
	 * @param ctx the parse tree
	 */
	void exitType_constant(TPTPv9Parser.Type_constantContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#type_functor}.
	 * @param ctx the parse tree
	 */
	void enterType_functor(TPTPv9Parser.Type_functorContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#type_functor}.
	 * @param ctx the parse tree
	 */
	void exitType_functor(TPTPv9Parser.Type_functorContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#defined_type}.
	 * @param ctx the parse tree
	 */
	void enterDefined_type(TPTPv9Parser.Defined_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#defined_type}.
	 * @param ctx the parse tree
	 */
	void exitDefined_type(TPTPv9Parser.Defined_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#atom}.
	 * @param ctx the parse tree
	 */
	void enterAtom(TPTPv9Parser.AtomContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#atom}.
	 * @param ctx the parse tree
	 */
	void exitAtom(TPTPv9Parser.AtomContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#untyped_atom}.
	 * @param ctx the parse tree
	 */
	void enterUntyped_atom(TPTPv9Parser.Untyped_atomContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#untyped_atom}.
	 * @param ctx the parse tree
	 */
	void exitUntyped_atom(TPTPv9Parser.Untyped_atomContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#defined_infix_pred}.
	 * @param ctx the parse tree
	 */
	void enterDefined_infix_pred(TPTPv9Parser.Defined_infix_predContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#defined_infix_pred}.
	 * @param ctx the parse tree
	 */
	void exitDefined_infix_pred(TPTPv9Parser.Defined_infix_predContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#infix_equality}.
	 * @param ctx the parse tree
	 */
	void enterInfix_equality(TPTPv9Parser.Infix_equalityContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#infix_equality}.
	 * @param ctx the parse tree
	 */
	void exitInfix_equality(TPTPv9Parser.Infix_equalityContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#infix_inequality}.
	 * @param ctx the parse tree
	 */
	void enterInfix_inequality(TPTPv9Parser.Infix_inequalityContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#infix_inequality}.
	 * @param ctx the parse tree
	 */
	void exitInfix_inequality(TPTPv9Parser.Infix_inequalityContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#constant}.
	 * @param ctx the parse tree
	 */
	void enterConstant(TPTPv9Parser.ConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#constant}.
	 * @param ctx the parse tree
	 */
	void exitConstant(TPTPv9Parser.ConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#functor}.
	 * @param ctx the parse tree
	 */
	void enterFunctor(TPTPv9Parser.FunctorContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#functor}.
	 * @param ctx the parse tree
	 */
	void exitFunctor(TPTPv9Parser.FunctorContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#defined_constant}.
	 * @param ctx the parse tree
	 */
	void enterDefined_constant(TPTPv9Parser.Defined_constantContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#defined_constant}.
	 * @param ctx the parse tree
	 */
	void exitDefined_constant(TPTPv9Parser.Defined_constantContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#defined_functor}.
	 * @param ctx the parse tree
	 */
	void enterDefined_functor(TPTPv9Parser.Defined_functorContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#defined_functor}.
	 * @param ctx the parse tree
	 */
	void exitDefined_functor(TPTPv9Parser.Defined_functorContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#system_constant}.
	 * @param ctx the parse tree
	 */
	void enterSystem_constant(TPTPv9Parser.System_constantContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#system_constant}.
	 * @param ctx the parse tree
	 */
	void exitSystem_constant(TPTPv9Parser.System_constantContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#system_functor}.
	 * @param ctx the parse tree
	 */
	void enterSystem_functor(TPTPv9Parser.System_functorContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#system_functor}.
	 * @param ctx the parse tree
	 */
	void exitSystem_functor(TPTPv9Parser.System_functorContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#def_or_sys_constant}.
	 * @param ctx the parse tree
	 */
	void enterDef_or_sys_constant(TPTPv9Parser.Def_or_sys_constantContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#def_or_sys_constant}.
	 * @param ctx the parse tree
	 */
	void exitDef_or_sys_constant(TPTPv9Parser.Def_or_sys_constantContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#th1_defined_term}.
	 * @param ctx the parse tree
	 */
	void enterTh1_defined_term(TPTPv9Parser.Th1_defined_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#th1_defined_term}.
	 * @param ctx the parse tree
	 */
	void exitTh1_defined_term(TPTPv9Parser.Th1_defined_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#defined_term}.
	 * @param ctx the parse tree
	 */
	void enterDefined_term(TPTPv9Parser.Defined_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#defined_term}.
	 * @param ctx the parse tree
	 */
	void exitDefined_term(TPTPv9Parser.Defined_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(TPTPv9Parser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(TPTPv9Parser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#source}.
	 * @param ctx the parse tree
	 */
	void enterSource(TPTPv9Parser.SourceContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#source}.
	 * @param ctx the parse tree
	 */
	void exitSource(TPTPv9Parser.SourceContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#sources}.
	 * @param ctx the parse tree
	 */
	void enterSources(TPTPv9Parser.SourcesContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#sources}.
	 * @param ctx the parse tree
	 */
	void exitSources(TPTPv9Parser.SourcesContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#dag_source}.
	 * @param ctx the parse tree
	 */
	void enterDag_source(TPTPv9Parser.Dag_sourceContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#dag_source}.
	 * @param ctx the parse tree
	 */
	void exitDag_source(TPTPv9Parser.Dag_sourceContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#inference_record}.
	 * @param ctx the parse tree
	 */
	void enterInference_record(TPTPv9Parser.Inference_recordContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#inference_record}.
	 * @param ctx the parse tree
	 */
	void exitInference_record(TPTPv9Parser.Inference_recordContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#inference_rule}.
	 * @param ctx the parse tree
	 */
	void enterInference_rule(TPTPv9Parser.Inference_ruleContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#inference_rule}.
	 * @param ctx the parse tree
	 */
	void exitInference_rule(TPTPv9Parser.Inference_ruleContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#internal_source}.
	 * @param ctx the parse tree
	 */
	void enterInternal_source(TPTPv9Parser.Internal_sourceContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#internal_source}.
	 * @param ctx the parse tree
	 */
	void exitInternal_source(TPTPv9Parser.Internal_sourceContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#intro_type}.
	 * @param ctx the parse tree
	 */
	void enterIntro_type(TPTPv9Parser.Intro_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#intro_type}.
	 * @param ctx the parse tree
	 */
	void exitIntro_type(TPTPv9Parser.Intro_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#external_source}.
	 * @param ctx the parse tree
	 */
	void enterExternal_source(TPTPv9Parser.External_sourceContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#external_source}.
	 * @param ctx the parse tree
	 */
	void exitExternal_source(TPTPv9Parser.External_sourceContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#file_source}.
	 * @param ctx the parse tree
	 */
	void enterFile_source(TPTPv9Parser.File_sourceContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#file_source}.
	 * @param ctx the parse tree
	 */
	void exitFile_source(TPTPv9Parser.File_sourceContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#file_info}.
	 * @param ctx the parse tree
	 */
	void enterFile_info(TPTPv9Parser.File_infoContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#file_info}.
	 * @param ctx the parse tree
	 */
	void exitFile_info(TPTPv9Parser.File_infoContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#theory}.
	 * @param ctx the parse tree
	 */
	void enterTheory(TPTPv9Parser.TheoryContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#theory}.
	 * @param ctx the parse tree
	 */
	void exitTheory(TPTPv9Parser.TheoryContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#theory_name}.
	 * @param ctx the parse tree
	 */
	void enterTheory_name(TPTPv9Parser.Theory_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#theory_name}.
	 * @param ctx the parse tree
	 */
	void exitTheory_name(TPTPv9Parser.Theory_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#creator_source}.
	 * @param ctx the parse tree
	 */
	void enterCreator_source(TPTPv9Parser.Creator_sourceContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#creator_source}.
	 * @param ctx the parse tree
	 */
	void exitCreator_source(TPTPv9Parser.Creator_sourceContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#creator_name}.
	 * @param ctx the parse tree
	 */
	void enterCreator_name(TPTPv9Parser.Creator_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#creator_name}.
	 * @param ctx the parse tree
	 */
	void exitCreator_name(TPTPv9Parser.Creator_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#parents}.
	 * @param ctx the parse tree
	 */
	void enterParents(TPTPv9Parser.ParentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#parents}.
	 * @param ctx the parse tree
	 */
	void exitParents(TPTPv9Parser.ParentsContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#parent_list}.
	 * @param ctx the parse tree
	 */
	void enterParent_list(TPTPv9Parser.Parent_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#parent_list}.
	 * @param ctx the parse tree
	 */
	void exitParent_list(TPTPv9Parser.Parent_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#parent_info}.
	 * @param ctx the parse tree
	 */
	void enterParent_info(TPTPv9Parser.Parent_infoContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#parent_info}.
	 * @param ctx the parse tree
	 */
	void exitParent_info(TPTPv9Parser.Parent_infoContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#parent_details}.
	 * @param ctx the parse tree
	 */
	void enterParent_details(TPTPv9Parser.Parent_detailsContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#parent_details}.
	 * @param ctx the parse tree
	 */
	void exitParent_details(TPTPv9Parser.Parent_detailsContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#optional_info}.
	 * @param ctx the parse tree
	 */
	void enterOptional_info(TPTPv9Parser.Optional_infoContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#optional_info}.
	 * @param ctx the parse tree
	 */
	void exitOptional_info(TPTPv9Parser.Optional_infoContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#useful_info}.
	 * @param ctx the parse tree
	 */
	void enterUseful_info(TPTPv9Parser.Useful_infoContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#useful_info}.
	 * @param ctx the parse tree
	 */
	void exitUseful_info(TPTPv9Parser.Useful_infoContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#include}.
	 * @param ctx the parse tree
	 */
	void enterInclude(TPTPv9Parser.IncludeContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#include}.
	 * @param ctx the parse tree
	 */
	void exitInclude(TPTPv9Parser.IncludeContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#include_optionals}.
	 * @param ctx the parse tree
	 */
	void enterInclude_optionals(TPTPv9Parser.Include_optionalsContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#include_optionals}.
	 * @param ctx the parse tree
	 */
	void exitInclude_optionals(TPTPv9Parser.Include_optionalsContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#formula_selection}.
	 * @param ctx the parse tree
	 */
	void enterFormula_selection(TPTPv9Parser.Formula_selectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#formula_selection}.
	 * @param ctx the parse tree
	 */
	void exitFormula_selection(TPTPv9Parser.Formula_selectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#name_list}.
	 * @param ctx the parse tree
	 */
	void enterName_list(TPTPv9Parser.Name_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#name_list}.
	 * @param ctx the parse tree
	 */
	void exitName_list(TPTPv9Parser.Name_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#space_name}.
	 * @param ctx the parse tree
	 */
	void enterSpace_name(TPTPv9Parser.Space_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#space_name}.
	 * @param ctx the parse tree
	 */
	void exitSpace_name(TPTPv9Parser.Space_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#general_term}.
	 * @param ctx the parse tree
	 */
	void enterGeneral_term(TPTPv9Parser.General_termContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#general_term}.
	 * @param ctx the parse tree
	 */
	void exitGeneral_term(TPTPv9Parser.General_termContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#general_data}.
	 * @param ctx the parse tree
	 */
	void enterGeneral_data(TPTPv9Parser.General_dataContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#general_data}.
	 * @param ctx the parse tree
	 */
	void exitGeneral_data(TPTPv9Parser.General_dataContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#general_function}.
	 * @param ctx the parse tree
	 */
	void enterGeneral_function(TPTPv9Parser.General_functionContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#general_function}.
	 * @param ctx the parse tree
	 */
	void exitGeneral_function(TPTPv9Parser.General_functionContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#formula_data}.
	 * @param ctx the parse tree
	 */
	void enterFormula_data(TPTPv9Parser.Formula_dataContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#formula_data}.
	 * @param ctx the parse tree
	 */
	void exitFormula_data(TPTPv9Parser.Formula_dataContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#general_list}.
	 * @param ctx the parse tree
	 */
	void enterGeneral_list(TPTPv9Parser.General_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#general_list}.
	 * @param ctx the parse tree
	 */
	void exitGeneral_list(TPTPv9Parser.General_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#general_terms}.
	 * @param ctx the parse tree
	 */
	void enterGeneral_terms(TPTPv9Parser.General_termsContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#general_terms}.
	 * @param ctx the parse tree
	 */
	void exitGeneral_terms(TPTPv9Parser.General_termsContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#name}.
	 * @param ctx the parse tree
	 */
	void enterName(TPTPv9Parser.NameContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#name}.
	 * @param ctx the parse tree
	 */
	void exitName(TPTPv9Parser.NameContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#atomic_word}.
	 * @param ctx the parse tree
	 */
	void enterAtomic_word(TPTPv9Parser.Atomic_wordContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#atomic_word}.
	 * @param ctx the parse tree
	 */
	void exitAtomic_word(TPTPv9Parser.Atomic_wordContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#atomic_defined_word}.
	 * @param ctx the parse tree
	 */
	void enterAtomic_defined_word(TPTPv9Parser.Atomic_defined_wordContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#atomic_defined_word}.
	 * @param ctx the parse tree
	 */
	void exitAtomic_defined_word(TPTPv9Parser.Atomic_defined_wordContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#atomic_system_word}.
	 * @param ctx the parse tree
	 */
	void enterAtomic_system_word(TPTPv9Parser.Atomic_system_wordContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#atomic_system_word}.
	 * @param ctx the parse tree
	 */
	void exitAtomic_system_word(TPTPv9Parser.Atomic_system_wordContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#number}.
	 * @param ctx the parse tree
	 */
	void enterNumber(TPTPv9Parser.NumberContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#number}.
	 * @param ctx the parse tree
	 */
	void exitNumber(TPTPv9Parser.NumberContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#file_name}.
	 * @param ctx the parse tree
	 */
	void enterFile_name(TPTPv9Parser.File_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#file_name}.
	 * @param ctx the parse tree
	 */
	void exitFile_name(TPTPv9Parser.File_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link TPTPv9Parser#null}.
	 * @param ctx the parse tree
	 */
	void enterNull(TPTPv9Parser.NullContext ctx);
	/**
	 * Exit a parse tree produced by {@link TPTPv9Parser#null}.
	 * @param ctx the parse tree
	 */
	void exitNull(TPTPv9Parser.NullContext ctx);
}