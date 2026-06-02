# Generated from ANTLRGrammar/TPTP.g4 by ANTLR 4.13.2
from antlr4 import *
if "." in __name__:
    from .TPTPParser import TPTPParser
else:
    from TPTPParser import TPTPParser

# This class defines a complete listener for a parse tree produced by TPTPParser.
class TPTPListener(ParseTreeListener):

    # Enter a parse tree produced by TPTPParser#tptp_file.
    def enterTptp_file(self, ctx:TPTPParser.Tptp_fileContext):
        pass

    # Exit a parse tree produced by TPTPParser#tptp_file.
    def exitTptp_file(self, ctx:TPTPParser.Tptp_fileContext):
        pass


    # Enter a parse tree produced by TPTPParser#tptp_input.
    def enterTptp_input(self, ctx:TPTPParser.Tptp_inputContext):
        pass

    # Exit a parse tree produced by TPTPParser#tptp_input.
    def exitTptp_input(self, ctx:TPTPParser.Tptp_inputContext):
        pass


    # Enter a parse tree produced by TPTPParser#annotated_formula.
    def enterAnnotated_formula(self, ctx:TPTPParser.Annotated_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#annotated_formula.
    def exitAnnotated_formula(self, ctx:TPTPParser.Annotated_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#tpi_annotated.
    def enterTpi_annotated(self, ctx:TPTPParser.Tpi_annotatedContext):
        pass

    # Exit a parse tree produced by TPTPParser#tpi_annotated.
    def exitTpi_annotated(self, ctx:TPTPParser.Tpi_annotatedContext):
        pass


    # Enter a parse tree produced by TPTPParser#tpi_formula.
    def enterTpi_formula(self, ctx:TPTPParser.Tpi_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tpi_formula.
    def exitTpi_formula(self, ctx:TPTPParser.Tpi_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_annotated.
    def enterThf_annotated(self, ctx:TPTPParser.Thf_annotatedContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_annotated.
    def exitThf_annotated(self, ctx:TPTPParser.Thf_annotatedContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_annotated.
    def enterTff_annotated(self, ctx:TPTPParser.Tff_annotatedContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_annotated.
    def exitTff_annotated(self, ctx:TPTPParser.Tff_annotatedContext):
        pass


    # Enter a parse tree produced by TPTPParser#tcf_annotated.
    def enterTcf_annotated(self, ctx:TPTPParser.Tcf_annotatedContext):
        pass

    # Exit a parse tree produced by TPTPParser#tcf_annotated.
    def exitTcf_annotated(self, ctx:TPTPParser.Tcf_annotatedContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_annotated.
    def enterFof_annotated(self, ctx:TPTPParser.Fof_annotatedContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_annotated.
    def exitFof_annotated(self, ctx:TPTPParser.Fof_annotatedContext):
        pass


    # Enter a parse tree produced by TPTPParser#cnf_annotated.
    def enterCnf_annotated(self, ctx:TPTPParser.Cnf_annotatedContext):
        pass

    # Exit a parse tree produced by TPTPParser#cnf_annotated.
    def exitCnf_annotated(self, ctx:TPTPParser.Cnf_annotatedContext):
        pass


    # Enter a parse tree produced by TPTPParser#annotations.
    def enterAnnotations(self, ctx:TPTPParser.AnnotationsContext):
        pass

    # Exit a parse tree produced by TPTPParser#annotations.
    def exitAnnotations(self, ctx:TPTPParser.AnnotationsContext):
        pass


    # Enter a parse tree produced by TPTPParser#formula_role.
    def enterFormula_role(self, ctx:TPTPParser.Formula_roleContext):
        pass

    # Exit a parse tree produced by TPTPParser#formula_role.
    def exitFormula_role(self, ctx:TPTPParser.Formula_roleContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_formula.
    def enterThf_formula(self, ctx:TPTPParser.Thf_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_formula.
    def exitThf_formula(self, ctx:TPTPParser.Thf_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_logic_formula.
    def enterThf_logic_formula(self, ctx:TPTPParser.Thf_logic_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_logic_formula.
    def exitThf_logic_formula(self, ctx:TPTPParser.Thf_logic_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_binary_formula.
    def enterThf_binary_formula(self, ctx:TPTPParser.Thf_binary_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_binary_formula.
    def exitThf_binary_formula(self, ctx:TPTPParser.Thf_binary_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_binary_nonassoc.
    def enterThf_binary_nonassoc(self, ctx:TPTPParser.Thf_binary_nonassocContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_binary_nonassoc.
    def exitThf_binary_nonassoc(self, ctx:TPTPParser.Thf_binary_nonassocContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_binary_assoc.
    def enterThf_binary_assoc(self, ctx:TPTPParser.Thf_binary_assocContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_binary_assoc.
    def exitThf_binary_assoc(self, ctx:TPTPParser.Thf_binary_assocContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_or_formula.
    def enterThf_or_formula(self, ctx:TPTPParser.Thf_or_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_or_formula.
    def exitThf_or_formula(self, ctx:TPTPParser.Thf_or_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_and_formula.
    def enterThf_and_formula(self, ctx:TPTPParser.Thf_and_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_and_formula.
    def exitThf_and_formula(self, ctx:TPTPParser.Thf_and_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_apply_formula.
    def enterThf_apply_formula(self, ctx:TPTPParser.Thf_apply_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_apply_formula.
    def exitThf_apply_formula(self, ctx:TPTPParser.Thf_apply_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_unit_formula.
    def enterThf_unit_formula(self, ctx:TPTPParser.Thf_unit_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_unit_formula.
    def exitThf_unit_formula(self, ctx:TPTPParser.Thf_unit_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_preunit_formula.
    def enterThf_preunit_formula(self, ctx:TPTPParser.Thf_preunit_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_preunit_formula.
    def exitThf_preunit_formula(self, ctx:TPTPParser.Thf_preunit_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_unitary_formula.
    def enterThf_unitary_formula(self, ctx:TPTPParser.Thf_unitary_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_unitary_formula.
    def exitThf_unitary_formula(self, ctx:TPTPParser.Thf_unitary_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_quantified_formula.
    def enterThf_quantified_formula(self, ctx:TPTPParser.Thf_quantified_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_quantified_formula.
    def exitThf_quantified_formula(self, ctx:TPTPParser.Thf_quantified_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_quantification.
    def enterThf_quantification(self, ctx:TPTPParser.Thf_quantificationContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_quantification.
    def exitThf_quantification(self, ctx:TPTPParser.Thf_quantificationContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_variable_list.
    def enterThf_variable_list(self, ctx:TPTPParser.Thf_variable_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_variable_list.
    def exitThf_variable_list(self, ctx:TPTPParser.Thf_variable_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_typed_variable.
    def enterThf_typed_variable(self, ctx:TPTPParser.Thf_typed_variableContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_typed_variable.
    def exitThf_typed_variable(self, ctx:TPTPParser.Thf_typed_variableContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_unary_formula.
    def enterThf_unary_formula(self, ctx:TPTPParser.Thf_unary_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_unary_formula.
    def exitThf_unary_formula(self, ctx:TPTPParser.Thf_unary_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_prefix_unary.
    def enterThf_prefix_unary(self, ctx:TPTPParser.Thf_prefix_unaryContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_prefix_unary.
    def exitThf_prefix_unary(self, ctx:TPTPParser.Thf_prefix_unaryContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_infix_unary.
    def enterThf_infix_unary(self, ctx:TPTPParser.Thf_infix_unaryContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_infix_unary.
    def exitThf_infix_unary(self, ctx:TPTPParser.Thf_infix_unaryContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_atomic_formula.
    def enterThf_atomic_formula(self, ctx:TPTPParser.Thf_atomic_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_atomic_formula.
    def exitThf_atomic_formula(self, ctx:TPTPParser.Thf_atomic_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_plain_atomic.
    def enterThf_plain_atomic(self, ctx:TPTPParser.Thf_plain_atomicContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_plain_atomic.
    def exitThf_plain_atomic(self, ctx:TPTPParser.Thf_plain_atomicContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_defined_atomic.
    def enterThf_defined_atomic(self, ctx:TPTPParser.Thf_defined_atomicContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_defined_atomic.
    def exitThf_defined_atomic(self, ctx:TPTPParser.Thf_defined_atomicContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_defined_term.
    def enterThf_defined_term(self, ctx:TPTPParser.Thf_defined_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_defined_term.
    def exitThf_defined_term(self, ctx:TPTPParser.Thf_defined_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_defined_infix.
    def enterThf_defined_infix(self, ctx:TPTPParser.Thf_defined_infixContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_defined_infix.
    def exitThf_defined_infix(self, ctx:TPTPParser.Thf_defined_infixContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_system_atomic.
    def enterThf_system_atomic(self, ctx:TPTPParser.Thf_system_atomicContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_system_atomic.
    def exitThf_system_atomic(self, ctx:TPTPParser.Thf_system_atomicContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_let.
    def enterThf_let(self, ctx:TPTPParser.Thf_letContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_let.
    def exitThf_let(self, ctx:TPTPParser.Thf_letContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_let_types.
    def enterThf_let_types(self, ctx:TPTPParser.Thf_let_typesContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_let_types.
    def exitThf_let_types(self, ctx:TPTPParser.Thf_let_typesContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_atom_typing_list.
    def enterThf_atom_typing_list(self, ctx:TPTPParser.Thf_atom_typing_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_atom_typing_list.
    def exitThf_atom_typing_list(self, ctx:TPTPParser.Thf_atom_typing_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_let_defns.
    def enterThf_let_defns(self, ctx:TPTPParser.Thf_let_defnsContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_let_defns.
    def exitThf_let_defns(self, ctx:TPTPParser.Thf_let_defnsContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_let_defn.
    def enterThf_let_defn(self, ctx:TPTPParser.Thf_let_defnContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_let_defn.
    def exitThf_let_defn(self, ctx:TPTPParser.Thf_let_defnContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_let_defn_list.
    def enterThf_let_defn_list(self, ctx:TPTPParser.Thf_let_defn_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_let_defn_list.
    def exitThf_let_defn_list(self, ctx:TPTPParser.Thf_let_defn_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_unitary_term.
    def enterThf_unitary_term(self, ctx:TPTPParser.Thf_unitary_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_unitary_term.
    def exitThf_unitary_term(self, ctx:TPTPParser.Thf_unitary_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_conn_term.
    def enterThf_conn_term(self, ctx:TPTPParser.Thf_conn_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_conn_term.
    def exitThf_conn_term(self, ctx:TPTPParser.Thf_conn_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_tuple.
    def enterThf_tuple(self, ctx:TPTPParser.Thf_tupleContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_tuple.
    def exitThf_tuple(self, ctx:TPTPParser.Thf_tupleContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_formula_list.
    def enterThf_formula_list(self, ctx:TPTPParser.Thf_formula_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_formula_list.
    def exitThf_formula_list(self, ctx:TPTPParser.Thf_formula_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#comma_thf_logic_formula.
    def enterComma_thf_logic_formula(self, ctx:TPTPParser.Comma_thf_logic_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#comma_thf_logic_formula.
    def exitComma_thf_logic_formula(self, ctx:TPTPParser.Comma_thf_logic_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_atom_typing.
    def enterThf_atom_typing(self, ctx:TPTPParser.Thf_atom_typingContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_atom_typing.
    def exitThf_atom_typing(self, ctx:TPTPParser.Thf_atom_typingContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_top_level_type.
    def enterThf_top_level_type(self, ctx:TPTPParser.Thf_top_level_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_top_level_type.
    def exitThf_top_level_type(self, ctx:TPTPParser.Thf_top_level_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_unitary_type.
    def enterThf_unitary_type(self, ctx:TPTPParser.Thf_unitary_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_unitary_type.
    def exitThf_unitary_type(self, ctx:TPTPParser.Thf_unitary_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_apply_type.
    def enterThf_apply_type(self, ctx:TPTPParser.Thf_apply_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_apply_type.
    def exitThf_apply_type(self, ctx:TPTPParser.Thf_apply_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_binary_type.
    def enterThf_binary_type(self, ctx:TPTPParser.Thf_binary_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_binary_type.
    def exitThf_binary_type(self, ctx:TPTPParser.Thf_binary_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_mapping_type.
    def enterThf_mapping_type(self, ctx:TPTPParser.Thf_mapping_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_mapping_type.
    def exitThf_mapping_type(self, ctx:TPTPParser.Thf_mapping_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_xprod_type.
    def enterThf_xprod_type(self, ctx:TPTPParser.Thf_xprod_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_xprod_type.
    def exitThf_xprod_type(self, ctx:TPTPParser.Thf_xprod_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_union_type.
    def enterThf_union_type(self, ctx:TPTPParser.Thf_union_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_union_type.
    def exitThf_union_type(self, ctx:TPTPParser.Thf_union_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_subtype.
    def enterThf_subtype(self, ctx:TPTPParser.Thf_subtypeContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_subtype.
    def exitThf_subtype(self, ctx:TPTPParser.Thf_subtypeContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_definition.
    def enterThf_definition(self, ctx:TPTPParser.Thf_definitionContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_definition.
    def exitThf_definition(self, ctx:TPTPParser.Thf_definitionContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_sequent.
    def enterThf_sequent(self, ctx:TPTPParser.Thf_sequentContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_sequent.
    def exitThf_sequent(self, ctx:TPTPParser.Thf_sequentContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_formula.
    def enterTff_formula(self, ctx:TPTPParser.Tff_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_formula.
    def exitTff_formula(self, ctx:TPTPParser.Tff_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_logic_formula.
    def enterTff_logic_formula(self, ctx:TPTPParser.Tff_logic_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_logic_formula.
    def exitTff_logic_formula(self, ctx:TPTPParser.Tff_logic_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_binary_formula.
    def enterTff_binary_formula(self, ctx:TPTPParser.Tff_binary_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_binary_formula.
    def exitTff_binary_formula(self, ctx:TPTPParser.Tff_binary_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_binary_nonassoc.
    def enterTff_binary_nonassoc(self, ctx:TPTPParser.Tff_binary_nonassocContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_binary_nonassoc.
    def exitTff_binary_nonassoc(self, ctx:TPTPParser.Tff_binary_nonassocContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_binary_assoc.
    def enterTff_binary_assoc(self, ctx:TPTPParser.Tff_binary_assocContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_binary_assoc.
    def exitTff_binary_assoc(self, ctx:TPTPParser.Tff_binary_assocContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_or_formula.
    def enterTff_or_formula(self, ctx:TPTPParser.Tff_or_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_or_formula.
    def exitTff_or_formula(self, ctx:TPTPParser.Tff_or_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_and_formula.
    def enterTff_and_formula(self, ctx:TPTPParser.Tff_and_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_and_formula.
    def exitTff_and_formula(self, ctx:TPTPParser.Tff_and_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_unit_formula.
    def enterTff_unit_formula(self, ctx:TPTPParser.Tff_unit_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_unit_formula.
    def exitTff_unit_formula(self, ctx:TPTPParser.Tff_unit_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_preunit_formula.
    def enterTff_preunit_formula(self, ctx:TPTPParser.Tff_preunit_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_preunit_formula.
    def exitTff_preunit_formula(self, ctx:TPTPParser.Tff_preunit_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_unitary_formula.
    def enterTff_unitary_formula(self, ctx:TPTPParser.Tff_unitary_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_unitary_formula.
    def exitTff_unitary_formula(self, ctx:TPTPParser.Tff_unitary_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#txf_unitary_formula.
    def enterTxf_unitary_formula(self, ctx:TPTPParser.Txf_unitary_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#txf_unitary_formula.
    def exitTxf_unitary_formula(self, ctx:TPTPParser.Txf_unitary_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_quantified_formula.
    def enterTff_quantified_formula(self, ctx:TPTPParser.Tff_quantified_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_quantified_formula.
    def exitTff_quantified_formula(self, ctx:TPTPParser.Tff_quantified_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_variable_list.
    def enterTff_variable_list(self, ctx:TPTPParser.Tff_variable_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_variable_list.
    def exitTff_variable_list(self, ctx:TPTPParser.Tff_variable_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_variable.
    def enterTff_variable(self, ctx:TPTPParser.Tff_variableContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_variable.
    def exitTff_variable(self, ctx:TPTPParser.Tff_variableContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_typed_variable.
    def enterTff_typed_variable(self, ctx:TPTPParser.Tff_typed_variableContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_typed_variable.
    def exitTff_typed_variable(self, ctx:TPTPParser.Tff_typed_variableContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_unary_formula.
    def enterTff_unary_formula(self, ctx:TPTPParser.Tff_unary_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_unary_formula.
    def exitTff_unary_formula(self, ctx:TPTPParser.Tff_unary_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_prefix_unary.
    def enterTff_prefix_unary(self, ctx:TPTPParser.Tff_prefix_unaryContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_prefix_unary.
    def exitTff_prefix_unary(self, ctx:TPTPParser.Tff_prefix_unaryContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_infix_unary.
    def enterTff_infix_unary(self, ctx:TPTPParser.Tff_infix_unaryContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_infix_unary.
    def exitTff_infix_unary(self, ctx:TPTPParser.Tff_infix_unaryContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_atomic_formula.
    def enterTff_atomic_formula(self, ctx:TPTPParser.Tff_atomic_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_atomic_formula.
    def exitTff_atomic_formula(self, ctx:TPTPParser.Tff_atomic_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_plain_atomic.
    def enterTff_plain_atomic(self, ctx:TPTPParser.Tff_plain_atomicContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_plain_atomic.
    def exitTff_plain_atomic(self, ctx:TPTPParser.Tff_plain_atomicContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_defined_atomic.
    def enterTff_defined_atomic(self, ctx:TPTPParser.Tff_defined_atomicContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_defined_atomic.
    def exitTff_defined_atomic(self, ctx:TPTPParser.Tff_defined_atomicContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_defined_plain.
    def enterTff_defined_plain(self, ctx:TPTPParser.Tff_defined_plainContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_defined_plain.
    def exitTff_defined_plain(self, ctx:TPTPParser.Tff_defined_plainContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_defined_infix.
    def enterTff_defined_infix(self, ctx:TPTPParser.Tff_defined_infixContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_defined_infix.
    def exitTff_defined_infix(self, ctx:TPTPParser.Tff_defined_infixContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_system_atomic.
    def enterTff_system_atomic(self, ctx:TPTPParser.Tff_system_atomicContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_system_atomic.
    def exitTff_system_atomic(self, ctx:TPTPParser.Tff_system_atomicContext):
        pass


    # Enter a parse tree produced by TPTPParser#txf_let.
    def enterTxf_let(self, ctx:TPTPParser.Txf_letContext):
        pass

    # Exit a parse tree produced by TPTPParser#txf_let.
    def exitTxf_let(self, ctx:TPTPParser.Txf_letContext):
        pass


    # Enter a parse tree produced by TPTPParser#txf_let_types.
    def enterTxf_let_types(self, ctx:TPTPParser.Txf_let_typesContext):
        pass

    # Exit a parse tree produced by TPTPParser#txf_let_types.
    def exitTxf_let_types(self, ctx:TPTPParser.Txf_let_typesContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_atom_typing_list.
    def enterTff_atom_typing_list(self, ctx:TPTPParser.Tff_atom_typing_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_atom_typing_list.
    def exitTff_atom_typing_list(self, ctx:TPTPParser.Tff_atom_typing_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#txf_let_defns.
    def enterTxf_let_defns(self, ctx:TPTPParser.Txf_let_defnsContext):
        pass

    # Exit a parse tree produced by TPTPParser#txf_let_defns.
    def exitTxf_let_defns(self, ctx:TPTPParser.Txf_let_defnsContext):
        pass


    # Enter a parse tree produced by TPTPParser#txf_let_defn.
    def enterTxf_let_defn(self, ctx:TPTPParser.Txf_let_defnContext):
        pass

    # Exit a parse tree produced by TPTPParser#txf_let_defn.
    def exitTxf_let_defn(self, ctx:TPTPParser.Txf_let_defnContext):
        pass


    # Enter a parse tree produced by TPTPParser#txf_let_LHS.
    def enterTxf_let_LHS(self, ctx:TPTPParser.Txf_let_LHSContext):
        pass

    # Exit a parse tree produced by TPTPParser#txf_let_LHS.
    def exitTxf_let_LHS(self, ctx:TPTPParser.Txf_let_LHSContext):
        pass


    # Enter a parse tree produced by TPTPParser#txf_let_defn_list.
    def enterTxf_let_defn_list(self, ctx:TPTPParser.Txf_let_defn_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#txf_let_defn_list.
    def exitTxf_let_defn_list(self, ctx:TPTPParser.Txf_let_defn_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#nxf_atom.
    def enterNxf_atom(self, ctx:TPTPParser.Nxf_atomContext):
        pass

    # Exit a parse tree produced by TPTPParser#nxf_atom.
    def exitNxf_atom(self, ctx:TPTPParser.Nxf_atomContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_term.
    def enterTff_term(self, ctx:TPTPParser.Tff_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_term.
    def exitTff_term(self, ctx:TPTPParser.Tff_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_unitary_term.
    def enterTff_unitary_term(self, ctx:TPTPParser.Tff_unitary_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_unitary_term.
    def exitTff_unitary_term(self, ctx:TPTPParser.Tff_unitary_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#txf_tuple.
    def enterTxf_tuple(self, ctx:TPTPParser.Txf_tupleContext):
        pass

    # Exit a parse tree produced by TPTPParser#txf_tuple.
    def exitTxf_tuple(self, ctx:TPTPParser.Txf_tupleContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_arguments.
    def enterTff_arguments(self, ctx:TPTPParser.Tff_argumentsContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_arguments.
    def exitTff_arguments(self, ctx:TPTPParser.Tff_argumentsContext):
        pass


    # Enter a parse tree produced by TPTPParser#comma_tff_term.
    def enterComma_tff_term(self, ctx:TPTPParser.Comma_tff_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#comma_tff_term.
    def exitComma_tff_term(self, ctx:TPTPParser.Comma_tff_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_atom_typing.
    def enterTff_atom_typing(self, ctx:TPTPParser.Tff_atom_typingContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_atom_typing.
    def exitTff_atom_typing(self, ctx:TPTPParser.Tff_atom_typingContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_top_level_type.
    def enterTff_top_level_type(self, ctx:TPTPParser.Tff_top_level_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_top_level_type.
    def exitTff_top_level_type(self, ctx:TPTPParser.Tff_top_level_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_non_atomic_type.
    def enterTff_non_atomic_type(self, ctx:TPTPParser.Tff_non_atomic_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_non_atomic_type.
    def exitTff_non_atomic_type(self, ctx:TPTPParser.Tff_non_atomic_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#tf1_quantified_type.
    def enterTf1_quantified_type(self, ctx:TPTPParser.Tf1_quantified_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#tf1_quantified_type.
    def exitTf1_quantified_type(self, ctx:TPTPParser.Tf1_quantified_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_monotype.
    def enterTff_monotype(self, ctx:TPTPParser.Tff_monotypeContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_monotype.
    def exitTff_monotype(self, ctx:TPTPParser.Tff_monotypeContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_unitary_type.
    def enterTff_unitary_type(self, ctx:TPTPParser.Tff_unitary_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_unitary_type.
    def exitTff_unitary_type(self, ctx:TPTPParser.Tff_unitary_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_atomic_type.
    def enterTff_atomic_type(self, ctx:TPTPParser.Tff_atomic_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_atomic_type.
    def exitTff_atomic_type(self, ctx:TPTPParser.Tff_atomic_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_type_arguments.
    def enterTff_type_arguments(self, ctx:TPTPParser.Tff_type_argumentsContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_type_arguments.
    def exitTff_type_arguments(self, ctx:TPTPParser.Tff_type_argumentsContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_mapping_type.
    def enterTff_mapping_type(self, ctx:TPTPParser.Tff_mapping_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_mapping_type.
    def exitTff_mapping_type(self, ctx:TPTPParser.Tff_mapping_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_xprod_type.
    def enterTff_xprod_type(self, ctx:TPTPParser.Tff_xprod_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_xprod_type.
    def exitTff_xprod_type(self, ctx:TPTPParser.Tff_xprod_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#txf_tuple_type.
    def enterTxf_tuple_type(self, ctx:TPTPParser.Txf_tuple_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#txf_tuple_type.
    def exitTxf_tuple_type(self, ctx:TPTPParser.Txf_tuple_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_type_list.
    def enterTff_type_list(self, ctx:TPTPParser.Tff_type_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_type_list.
    def exitTff_type_list(self, ctx:TPTPParser.Tff_type_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_subtype.
    def enterTff_subtype(self, ctx:TPTPParser.Tff_subtypeContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_subtype.
    def exitTff_subtype(self, ctx:TPTPParser.Tff_subtypeContext):
        pass


    # Enter a parse tree produced by TPTPParser#txf_definition.
    def enterTxf_definition(self, ctx:TPTPParser.Txf_definitionContext):
        pass

    # Exit a parse tree produced by TPTPParser#txf_definition.
    def exitTxf_definition(self, ctx:TPTPParser.Txf_definitionContext):
        pass


    # Enter a parse tree produced by TPTPParser#txf_sequent.
    def enterTxf_sequent(self, ctx:TPTPParser.Txf_sequentContext):
        pass

    # Exit a parse tree produced by TPTPParser#txf_sequent.
    def exitTxf_sequent(self, ctx:TPTPParser.Txf_sequentContext):
        pass


    # Enter a parse tree produced by TPTPParser#nhf_long_connective.
    def enterNhf_long_connective(self, ctx:TPTPParser.Nhf_long_connectiveContext):
        pass

    # Exit a parse tree produced by TPTPParser#nhf_long_connective.
    def exitNhf_long_connective(self, ctx:TPTPParser.Nhf_long_connectiveContext):
        pass


    # Enter a parse tree produced by TPTPParser#nhf_parameter_list.
    def enterNhf_parameter_list(self, ctx:TPTPParser.Nhf_parameter_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#nhf_parameter_list.
    def exitNhf_parameter_list(self, ctx:TPTPParser.Nhf_parameter_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#nhf_parameter.
    def enterNhf_parameter(self, ctx:TPTPParser.Nhf_parameterContext):
        pass

    # Exit a parse tree produced by TPTPParser#nhf_parameter.
    def exitNhf_parameter(self, ctx:TPTPParser.Nhf_parameterContext):
        pass


    # Enter a parse tree produced by TPTPParser#nhf_key_pair.
    def enterNhf_key_pair(self, ctx:TPTPParser.Nhf_key_pairContext):
        pass

    # Exit a parse tree produced by TPTPParser#nhf_key_pair.
    def exitNhf_key_pair(self, ctx:TPTPParser.Nhf_key_pairContext):
        pass


    # Enter a parse tree produced by TPTPParser#nxf_long_connective.
    def enterNxf_long_connective(self, ctx:TPTPParser.Nxf_long_connectiveContext):
        pass

    # Exit a parse tree produced by TPTPParser#nxf_long_connective.
    def exitNxf_long_connective(self, ctx:TPTPParser.Nxf_long_connectiveContext):
        pass


    # Enter a parse tree produced by TPTPParser#nxf_parameter_list.
    def enterNxf_parameter_list(self, ctx:TPTPParser.Nxf_parameter_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#nxf_parameter_list.
    def exitNxf_parameter_list(self, ctx:TPTPParser.Nxf_parameter_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#nxf_parameter.
    def enterNxf_parameter(self, ctx:TPTPParser.Nxf_parameterContext):
        pass

    # Exit a parse tree produced by TPTPParser#nxf_parameter.
    def exitNxf_parameter(self, ctx:TPTPParser.Nxf_parameterContext):
        pass


    # Enter a parse tree produced by TPTPParser#nxf_key_pair.
    def enterNxf_key_pair(self, ctx:TPTPParser.Nxf_key_pairContext):
        pass

    # Exit a parse tree produced by TPTPParser#nxf_key_pair.
    def exitNxf_key_pair(self, ctx:TPTPParser.Nxf_key_pairContext):
        pass


    # Enter a parse tree produced by TPTPParser#ntf_connective_name.
    def enterNtf_connective_name(self, ctx:TPTPParser.Ntf_connective_nameContext):
        pass

    # Exit a parse tree produced by TPTPParser#ntf_connective_name.
    def exitNtf_connective_name(self, ctx:TPTPParser.Ntf_connective_nameContext):
        pass


    # Enter a parse tree produced by TPTPParser#ntf_defined_connective.
    def enterNtf_defined_connective(self, ctx:TPTPParser.Ntf_defined_connectiveContext):
        pass

    # Exit a parse tree produced by TPTPParser#ntf_defined_connective.
    def exitNtf_defined_connective(self, ctx:TPTPParser.Ntf_defined_connectiveContext):
        pass


    # Enter a parse tree produced by TPTPParser#ntf_index.
    def enterNtf_index(self, ctx:TPTPParser.Ntf_indexContext):
        pass

    # Exit a parse tree produced by TPTPParser#ntf_index.
    def exitNtf_index(self, ctx:TPTPParser.Ntf_indexContext):
        pass


    # Enter a parse tree produced by TPTPParser#ntf_short_connective.
    def enterNtf_short_connective(self, ctx:TPTPParser.Ntf_short_connectiveContext):
        pass

    # Exit a parse tree produced by TPTPParser#ntf_short_connective.
    def exitNtf_short_connective(self, ctx:TPTPParser.Ntf_short_connectiveContext):
        pass


    # Enter a parse tree produced by TPTPParser#tcf_formula.
    def enterTcf_formula(self, ctx:TPTPParser.Tcf_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tcf_formula.
    def exitTcf_formula(self, ctx:TPTPParser.Tcf_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#tcf_logic_formula.
    def enterTcf_logic_formula(self, ctx:TPTPParser.Tcf_logic_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tcf_logic_formula.
    def exitTcf_logic_formula(self, ctx:TPTPParser.Tcf_logic_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#tcf_quantified_formula.
    def enterTcf_quantified_formula(self, ctx:TPTPParser.Tcf_quantified_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#tcf_quantified_formula.
    def exitTcf_quantified_formula(self, ctx:TPTPParser.Tcf_quantified_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_formula.
    def enterFof_formula(self, ctx:TPTPParser.Fof_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_formula.
    def exitFof_formula(self, ctx:TPTPParser.Fof_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_logic_formula.
    def enterFof_logic_formula(self, ctx:TPTPParser.Fof_logic_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_logic_formula.
    def exitFof_logic_formula(self, ctx:TPTPParser.Fof_logic_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_binary_formula.
    def enterFof_binary_formula(self, ctx:TPTPParser.Fof_binary_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_binary_formula.
    def exitFof_binary_formula(self, ctx:TPTPParser.Fof_binary_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_binary_nonassoc.
    def enterFof_binary_nonassoc(self, ctx:TPTPParser.Fof_binary_nonassocContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_binary_nonassoc.
    def exitFof_binary_nonassoc(self, ctx:TPTPParser.Fof_binary_nonassocContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_binary_assoc.
    def enterFof_binary_assoc(self, ctx:TPTPParser.Fof_binary_assocContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_binary_assoc.
    def exitFof_binary_assoc(self, ctx:TPTPParser.Fof_binary_assocContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_or_formula.
    def enterFof_or_formula(self, ctx:TPTPParser.Fof_or_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_or_formula.
    def exitFof_or_formula(self, ctx:TPTPParser.Fof_or_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_and_formula.
    def enterFof_and_formula(self, ctx:TPTPParser.Fof_and_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_and_formula.
    def exitFof_and_formula(self, ctx:TPTPParser.Fof_and_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_unary_formula.
    def enterFof_unary_formula(self, ctx:TPTPParser.Fof_unary_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_unary_formula.
    def exitFof_unary_formula(self, ctx:TPTPParser.Fof_unary_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_infix_unary.
    def enterFof_infix_unary(self, ctx:TPTPParser.Fof_infix_unaryContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_infix_unary.
    def exitFof_infix_unary(self, ctx:TPTPParser.Fof_infix_unaryContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_unit_formula.
    def enterFof_unit_formula(self, ctx:TPTPParser.Fof_unit_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_unit_formula.
    def exitFof_unit_formula(self, ctx:TPTPParser.Fof_unit_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_unitary_formula.
    def enterFof_unitary_formula(self, ctx:TPTPParser.Fof_unitary_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_unitary_formula.
    def exitFof_unitary_formula(self, ctx:TPTPParser.Fof_unitary_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_quantified_formula.
    def enterFof_quantified_formula(self, ctx:TPTPParser.Fof_quantified_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_quantified_formula.
    def exitFof_quantified_formula(self, ctx:TPTPParser.Fof_quantified_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_variable_list.
    def enterFof_variable_list(self, ctx:TPTPParser.Fof_variable_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_variable_list.
    def exitFof_variable_list(self, ctx:TPTPParser.Fof_variable_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_atomic_formula.
    def enterFof_atomic_formula(self, ctx:TPTPParser.Fof_atomic_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_atomic_formula.
    def exitFof_atomic_formula(self, ctx:TPTPParser.Fof_atomic_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_plain_atomic_formula.
    def enterFof_plain_atomic_formula(self, ctx:TPTPParser.Fof_plain_atomic_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_plain_atomic_formula.
    def exitFof_plain_atomic_formula(self, ctx:TPTPParser.Fof_plain_atomic_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_defined_atomic_formula.
    def enterFof_defined_atomic_formula(self, ctx:TPTPParser.Fof_defined_atomic_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_defined_atomic_formula.
    def exitFof_defined_atomic_formula(self, ctx:TPTPParser.Fof_defined_atomic_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_defined_plain_formula.
    def enterFof_defined_plain_formula(self, ctx:TPTPParser.Fof_defined_plain_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_defined_plain_formula.
    def exitFof_defined_plain_formula(self, ctx:TPTPParser.Fof_defined_plain_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_defined_infix_formula.
    def enterFof_defined_infix_formula(self, ctx:TPTPParser.Fof_defined_infix_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_defined_infix_formula.
    def exitFof_defined_infix_formula(self, ctx:TPTPParser.Fof_defined_infix_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_system_atomic_formula.
    def enterFof_system_atomic_formula(self, ctx:TPTPParser.Fof_system_atomic_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_system_atomic_formula.
    def exitFof_system_atomic_formula(self, ctx:TPTPParser.Fof_system_atomic_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_plain_term.
    def enterFof_plain_term(self, ctx:TPTPParser.Fof_plain_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_plain_term.
    def exitFof_plain_term(self, ctx:TPTPParser.Fof_plain_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_defined_term.
    def enterFof_defined_term(self, ctx:TPTPParser.Fof_defined_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_defined_term.
    def exitFof_defined_term(self, ctx:TPTPParser.Fof_defined_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_defined_atomic_term.
    def enterFof_defined_atomic_term(self, ctx:TPTPParser.Fof_defined_atomic_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_defined_atomic_term.
    def exitFof_defined_atomic_term(self, ctx:TPTPParser.Fof_defined_atomic_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_defined_plain_term.
    def enterFof_defined_plain_term(self, ctx:TPTPParser.Fof_defined_plain_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_defined_plain_term.
    def exitFof_defined_plain_term(self, ctx:TPTPParser.Fof_defined_plain_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_system_term.
    def enterFof_system_term(self, ctx:TPTPParser.Fof_system_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_system_term.
    def exitFof_system_term(self, ctx:TPTPParser.Fof_system_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_arguments.
    def enterFof_arguments(self, ctx:TPTPParser.Fof_argumentsContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_arguments.
    def exitFof_arguments(self, ctx:TPTPParser.Fof_argumentsContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_term.
    def enterFof_term(self, ctx:TPTPParser.Fof_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_term.
    def exitFof_term(self, ctx:TPTPParser.Fof_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_function_term.
    def enterFof_function_term(self, ctx:TPTPParser.Fof_function_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_function_term.
    def exitFof_function_term(self, ctx:TPTPParser.Fof_function_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_sequent.
    def enterFof_sequent(self, ctx:TPTPParser.Fof_sequentContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_sequent.
    def exitFof_sequent(self, ctx:TPTPParser.Fof_sequentContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_formula_tuple.
    def enterFof_formula_tuple(self, ctx:TPTPParser.Fof_formula_tupleContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_formula_tuple.
    def exitFof_formula_tuple(self, ctx:TPTPParser.Fof_formula_tupleContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_formula_tuple_list.
    def enterFof_formula_tuple_list(self, ctx:TPTPParser.Fof_formula_tuple_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_formula_tuple_list.
    def exitFof_formula_tuple_list(self, ctx:TPTPParser.Fof_formula_tuple_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#comma_fof_logic_formula.
    def enterComma_fof_logic_formula(self, ctx:TPTPParser.Comma_fof_logic_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#comma_fof_logic_formula.
    def exitComma_fof_logic_formula(self, ctx:TPTPParser.Comma_fof_logic_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#cnf_formula.
    def enterCnf_formula(self, ctx:TPTPParser.Cnf_formulaContext):
        pass

    # Exit a parse tree produced by TPTPParser#cnf_formula.
    def exitCnf_formula(self, ctx:TPTPParser.Cnf_formulaContext):
        pass


    # Enter a parse tree produced by TPTPParser#cnf_disjunction.
    def enterCnf_disjunction(self, ctx:TPTPParser.Cnf_disjunctionContext):
        pass

    # Exit a parse tree produced by TPTPParser#cnf_disjunction.
    def exitCnf_disjunction(self, ctx:TPTPParser.Cnf_disjunctionContext):
        pass


    # Enter a parse tree produced by TPTPParser#cnf_literal.
    def enterCnf_literal(self, ctx:TPTPParser.Cnf_literalContext):
        pass

    # Exit a parse tree produced by TPTPParser#cnf_literal.
    def exitCnf_literal(self, ctx:TPTPParser.Cnf_literalContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_quantifier.
    def enterThf_quantifier(self, ctx:TPTPParser.Thf_quantifierContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_quantifier.
    def exitThf_quantifier(self, ctx:TPTPParser.Thf_quantifierContext):
        pass


    # Enter a parse tree produced by TPTPParser#thf_unary_connective.
    def enterThf_unary_connective(self, ctx:TPTPParser.Thf_unary_connectiveContext):
        pass

    # Exit a parse tree produced by TPTPParser#thf_unary_connective.
    def exitThf_unary_connective(self, ctx:TPTPParser.Thf_unary_connectiveContext):
        pass


    # Enter a parse tree produced by TPTPParser#th0_quantifier.
    def enterTh0_quantifier(self, ctx:TPTPParser.Th0_quantifierContext):
        pass

    # Exit a parse tree produced by TPTPParser#th0_quantifier.
    def exitTh0_quantifier(self, ctx:TPTPParser.Th0_quantifierContext):
        pass


    # Enter a parse tree produced by TPTPParser#type_quantifier.
    def enterType_quantifier(self, ctx:TPTPParser.Type_quantifierContext):
        pass

    # Exit a parse tree produced by TPTPParser#type_quantifier.
    def exitType_quantifier(self, ctx:TPTPParser.Type_quantifierContext):
        pass


    # Enter a parse tree produced by TPTPParser#subtype_sign.
    def enterSubtype_sign(self, ctx:TPTPParser.Subtype_signContext):
        pass

    # Exit a parse tree produced by TPTPParser#subtype_sign.
    def exitSubtype_sign(self, ctx:TPTPParser.Subtype_signContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_unary_connective.
    def enterTff_unary_connective(self, ctx:TPTPParser.Tff_unary_connectiveContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_unary_connective.
    def exitTff_unary_connective(self, ctx:TPTPParser.Tff_unary_connectiveContext):
        pass


    # Enter a parse tree produced by TPTPParser#tff_quantifier.
    def enterTff_quantifier(self, ctx:TPTPParser.Tff_quantifierContext):
        pass

    # Exit a parse tree produced by TPTPParser#tff_quantifier.
    def exitTff_quantifier(self, ctx:TPTPParser.Tff_quantifierContext):
        pass


    # Enter a parse tree produced by TPTPParser#fof_quantifier.
    def enterFof_quantifier(self, ctx:TPTPParser.Fof_quantifierContext):
        pass

    # Exit a parse tree produced by TPTPParser#fof_quantifier.
    def exitFof_quantifier(self, ctx:TPTPParser.Fof_quantifierContext):
        pass


    # Enter a parse tree produced by TPTPParser#nonassoc_connective.
    def enterNonassoc_connective(self, ctx:TPTPParser.Nonassoc_connectiveContext):
        pass

    # Exit a parse tree produced by TPTPParser#nonassoc_connective.
    def exitNonassoc_connective(self, ctx:TPTPParser.Nonassoc_connectiveContext):
        pass


    # Enter a parse tree produced by TPTPParser#assoc_connective.
    def enterAssoc_connective(self, ctx:TPTPParser.Assoc_connectiveContext):
        pass

    # Exit a parse tree produced by TPTPParser#assoc_connective.
    def exitAssoc_connective(self, ctx:TPTPParser.Assoc_connectiveContext):
        pass


    # Enter a parse tree produced by TPTPParser#unary_connective.
    def enterUnary_connective(self, ctx:TPTPParser.Unary_connectiveContext):
        pass

    # Exit a parse tree produced by TPTPParser#unary_connective.
    def exitUnary_connective(self, ctx:TPTPParser.Unary_connectiveContext):
        pass


    # Enter a parse tree produced by TPTPParser#gentzen_arrow.
    def enterGentzen_arrow(self, ctx:TPTPParser.Gentzen_arrowContext):
        pass

    # Exit a parse tree produced by TPTPParser#gentzen_arrow.
    def exitGentzen_arrow(self, ctx:TPTPParser.Gentzen_arrowContext):
        pass


    # Enter a parse tree produced by TPTPParser#assignment.
    def enterAssignment(self, ctx:TPTPParser.AssignmentContext):
        pass

    # Exit a parse tree produced by TPTPParser#assignment.
    def exitAssignment(self, ctx:TPTPParser.AssignmentContext):
        pass


    # Enter a parse tree produced by TPTPParser#identical.
    def enterIdentical(self, ctx:TPTPParser.IdenticalContext):
        pass

    # Exit a parse tree produced by TPTPParser#identical.
    def exitIdentical(self, ctx:TPTPParser.IdenticalContext):
        pass


    # Enter a parse tree produced by TPTPParser#type_constant.
    def enterType_constant(self, ctx:TPTPParser.Type_constantContext):
        pass

    # Exit a parse tree produced by TPTPParser#type_constant.
    def exitType_constant(self, ctx:TPTPParser.Type_constantContext):
        pass


    # Enter a parse tree produced by TPTPParser#type_functor.
    def enterType_functor(self, ctx:TPTPParser.Type_functorContext):
        pass

    # Exit a parse tree produced by TPTPParser#type_functor.
    def exitType_functor(self, ctx:TPTPParser.Type_functorContext):
        pass


    # Enter a parse tree produced by TPTPParser#defined_type.
    def enterDefined_type(self, ctx:TPTPParser.Defined_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#defined_type.
    def exitDefined_type(self, ctx:TPTPParser.Defined_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#atom.
    def enterAtom(self, ctx:TPTPParser.AtomContext):
        pass

    # Exit a parse tree produced by TPTPParser#atom.
    def exitAtom(self, ctx:TPTPParser.AtomContext):
        pass


    # Enter a parse tree produced by TPTPParser#untyped_atom.
    def enterUntyped_atom(self, ctx:TPTPParser.Untyped_atomContext):
        pass

    # Exit a parse tree produced by TPTPParser#untyped_atom.
    def exitUntyped_atom(self, ctx:TPTPParser.Untyped_atomContext):
        pass


    # Enter a parse tree produced by TPTPParser#defined_infix_pred.
    def enterDefined_infix_pred(self, ctx:TPTPParser.Defined_infix_predContext):
        pass

    # Exit a parse tree produced by TPTPParser#defined_infix_pred.
    def exitDefined_infix_pred(self, ctx:TPTPParser.Defined_infix_predContext):
        pass


    # Enter a parse tree produced by TPTPParser#infix_equality.
    def enterInfix_equality(self, ctx:TPTPParser.Infix_equalityContext):
        pass

    # Exit a parse tree produced by TPTPParser#infix_equality.
    def exitInfix_equality(self, ctx:TPTPParser.Infix_equalityContext):
        pass


    # Enter a parse tree produced by TPTPParser#infix_inequality.
    def enterInfix_inequality(self, ctx:TPTPParser.Infix_inequalityContext):
        pass

    # Exit a parse tree produced by TPTPParser#infix_inequality.
    def exitInfix_inequality(self, ctx:TPTPParser.Infix_inequalityContext):
        pass


    # Enter a parse tree produced by TPTPParser#constant.
    def enterConstant(self, ctx:TPTPParser.ConstantContext):
        pass

    # Exit a parse tree produced by TPTPParser#constant.
    def exitConstant(self, ctx:TPTPParser.ConstantContext):
        pass


    # Enter a parse tree produced by TPTPParser#functor.
    def enterFunctor(self, ctx:TPTPParser.FunctorContext):
        pass

    # Exit a parse tree produced by TPTPParser#functor.
    def exitFunctor(self, ctx:TPTPParser.FunctorContext):
        pass


    # Enter a parse tree produced by TPTPParser#defined_constant.
    def enterDefined_constant(self, ctx:TPTPParser.Defined_constantContext):
        pass

    # Exit a parse tree produced by TPTPParser#defined_constant.
    def exitDefined_constant(self, ctx:TPTPParser.Defined_constantContext):
        pass


    # Enter a parse tree produced by TPTPParser#defined_functor.
    def enterDefined_functor(self, ctx:TPTPParser.Defined_functorContext):
        pass

    # Exit a parse tree produced by TPTPParser#defined_functor.
    def exitDefined_functor(self, ctx:TPTPParser.Defined_functorContext):
        pass


    # Enter a parse tree produced by TPTPParser#system_constant.
    def enterSystem_constant(self, ctx:TPTPParser.System_constantContext):
        pass

    # Exit a parse tree produced by TPTPParser#system_constant.
    def exitSystem_constant(self, ctx:TPTPParser.System_constantContext):
        pass


    # Enter a parse tree produced by TPTPParser#system_functor.
    def enterSystem_functor(self, ctx:TPTPParser.System_functorContext):
        pass

    # Exit a parse tree produced by TPTPParser#system_functor.
    def exitSystem_functor(self, ctx:TPTPParser.System_functorContext):
        pass


    # Enter a parse tree produced by TPTPParser#th1_defined_term.
    def enterTh1_defined_term(self, ctx:TPTPParser.Th1_defined_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#th1_defined_term.
    def exitTh1_defined_term(self, ctx:TPTPParser.Th1_defined_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#defined_term.
    def enterDefined_term(self, ctx:TPTPParser.Defined_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#defined_term.
    def exitDefined_term(self, ctx:TPTPParser.Defined_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#variable.
    def enterVariable(self, ctx:TPTPParser.VariableContext):
        pass

    # Exit a parse tree produced by TPTPParser#variable.
    def exitVariable(self, ctx:TPTPParser.VariableContext):
        pass


    # Enter a parse tree produced by TPTPParser#source.
    def enterSource(self, ctx:TPTPParser.SourceContext):
        pass

    # Exit a parse tree produced by TPTPParser#source.
    def exitSource(self, ctx:TPTPParser.SourceContext):
        pass


    # Enter a parse tree produced by TPTPParser#sources.
    def enterSources(self, ctx:TPTPParser.SourcesContext):
        pass

    # Exit a parse tree produced by TPTPParser#sources.
    def exitSources(self, ctx:TPTPParser.SourcesContext):
        pass


    # Enter a parse tree produced by TPTPParser#dag_source.
    def enterDag_source(self, ctx:TPTPParser.Dag_sourceContext):
        pass

    # Exit a parse tree produced by TPTPParser#dag_source.
    def exitDag_source(self, ctx:TPTPParser.Dag_sourceContext):
        pass


    # Enter a parse tree produced by TPTPParser#inference_record.
    def enterInference_record(self, ctx:TPTPParser.Inference_recordContext):
        pass

    # Exit a parse tree produced by TPTPParser#inference_record.
    def exitInference_record(self, ctx:TPTPParser.Inference_recordContext):
        pass


    # Enter a parse tree produced by TPTPParser#inference_rule.
    def enterInference_rule(self, ctx:TPTPParser.Inference_ruleContext):
        pass

    # Exit a parse tree produced by TPTPParser#inference_rule.
    def exitInference_rule(self, ctx:TPTPParser.Inference_ruleContext):
        pass


    # Enter a parse tree produced by TPTPParser#internal_source.
    def enterInternal_source(self, ctx:TPTPParser.Internal_sourceContext):
        pass

    # Exit a parse tree produced by TPTPParser#internal_source.
    def exitInternal_source(self, ctx:TPTPParser.Internal_sourceContext):
        pass


    # Enter a parse tree produced by TPTPParser#intro_type.
    def enterIntro_type(self, ctx:TPTPParser.Intro_typeContext):
        pass

    # Exit a parse tree produced by TPTPParser#intro_type.
    def exitIntro_type(self, ctx:TPTPParser.Intro_typeContext):
        pass


    # Enter a parse tree produced by TPTPParser#external_source.
    def enterExternal_source(self, ctx:TPTPParser.External_sourceContext):
        pass

    # Exit a parse tree produced by TPTPParser#external_source.
    def exitExternal_source(self, ctx:TPTPParser.External_sourceContext):
        pass


    # Enter a parse tree produced by TPTPParser#file_source.
    def enterFile_source(self, ctx:TPTPParser.File_sourceContext):
        pass

    # Exit a parse tree produced by TPTPParser#file_source.
    def exitFile_source(self, ctx:TPTPParser.File_sourceContext):
        pass


    # Enter a parse tree produced by TPTPParser#file_info.
    def enterFile_info(self, ctx:TPTPParser.File_infoContext):
        pass

    # Exit a parse tree produced by TPTPParser#file_info.
    def exitFile_info(self, ctx:TPTPParser.File_infoContext):
        pass


    # Enter a parse tree produced by TPTPParser#theory.
    def enterTheory(self, ctx:TPTPParser.TheoryContext):
        pass

    # Exit a parse tree produced by TPTPParser#theory.
    def exitTheory(self, ctx:TPTPParser.TheoryContext):
        pass


    # Enter a parse tree produced by TPTPParser#theory_name.
    def enterTheory_name(self, ctx:TPTPParser.Theory_nameContext):
        pass

    # Exit a parse tree produced by TPTPParser#theory_name.
    def exitTheory_name(self, ctx:TPTPParser.Theory_nameContext):
        pass


    # Enter a parse tree produced by TPTPParser#creator_source.
    def enterCreator_source(self, ctx:TPTPParser.Creator_sourceContext):
        pass

    # Exit a parse tree produced by TPTPParser#creator_source.
    def exitCreator_source(self, ctx:TPTPParser.Creator_sourceContext):
        pass


    # Enter a parse tree produced by TPTPParser#creator_name.
    def enterCreator_name(self, ctx:TPTPParser.Creator_nameContext):
        pass

    # Exit a parse tree produced by TPTPParser#creator_name.
    def exitCreator_name(self, ctx:TPTPParser.Creator_nameContext):
        pass


    # Enter a parse tree produced by TPTPParser#parents.
    def enterParents(self, ctx:TPTPParser.ParentsContext):
        pass

    # Exit a parse tree produced by TPTPParser#parents.
    def exitParents(self, ctx:TPTPParser.ParentsContext):
        pass


    # Enter a parse tree produced by TPTPParser#parent_list.
    def enterParent_list(self, ctx:TPTPParser.Parent_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#parent_list.
    def exitParent_list(self, ctx:TPTPParser.Parent_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#comma_parent_info.
    def enterComma_parent_info(self, ctx:TPTPParser.Comma_parent_infoContext):
        pass

    # Exit a parse tree produced by TPTPParser#comma_parent_info.
    def exitComma_parent_info(self, ctx:TPTPParser.Comma_parent_infoContext):
        pass


    # Enter a parse tree produced by TPTPParser#parent_info.
    def enterParent_info(self, ctx:TPTPParser.Parent_infoContext):
        pass

    # Exit a parse tree produced by TPTPParser#parent_info.
    def exitParent_info(self, ctx:TPTPParser.Parent_infoContext):
        pass


    # Enter a parse tree produced by TPTPParser#parent_details.
    def enterParent_details(self, ctx:TPTPParser.Parent_detailsContext):
        pass

    # Exit a parse tree produced by TPTPParser#parent_details.
    def exitParent_details(self, ctx:TPTPParser.Parent_detailsContext):
        pass


    # Enter a parse tree produced by TPTPParser#optional_info.
    def enterOptional_info(self, ctx:TPTPParser.Optional_infoContext):
        pass

    # Exit a parse tree produced by TPTPParser#optional_info.
    def exitOptional_info(self, ctx:TPTPParser.Optional_infoContext):
        pass


    # Enter a parse tree produced by TPTPParser#useful_info.
    def enterUseful_info(self, ctx:TPTPParser.Useful_infoContext):
        pass

    # Exit a parse tree produced by TPTPParser#useful_info.
    def exitUseful_info(self, ctx:TPTPParser.Useful_infoContext):
        pass


    # Enter a parse tree produced by TPTPParser#include.
    def enterInclude(self, ctx:TPTPParser.IncludeContext):
        pass

    # Exit a parse tree produced by TPTPParser#include.
    def exitInclude(self, ctx:TPTPParser.IncludeContext):
        pass


    # Enter a parse tree produced by TPTPParser#include_optionals.
    def enterInclude_optionals(self, ctx:TPTPParser.Include_optionalsContext):
        pass

    # Exit a parse tree produced by TPTPParser#include_optionals.
    def exitInclude_optionals(self, ctx:TPTPParser.Include_optionalsContext):
        pass


    # Enter a parse tree produced by TPTPParser#formula_selection.
    def enterFormula_selection(self, ctx:TPTPParser.Formula_selectionContext):
        pass

    # Exit a parse tree produced by TPTPParser#formula_selection.
    def exitFormula_selection(self, ctx:TPTPParser.Formula_selectionContext):
        pass


    # Enter a parse tree produced by TPTPParser#name_list.
    def enterName_list(self, ctx:TPTPParser.Name_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#name_list.
    def exitName_list(self, ctx:TPTPParser.Name_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#space_name.
    def enterSpace_name(self, ctx:TPTPParser.Space_nameContext):
        pass

    # Exit a parse tree produced by TPTPParser#space_name.
    def exitSpace_name(self, ctx:TPTPParser.Space_nameContext):
        pass


    # Enter a parse tree produced by TPTPParser#general_term.
    def enterGeneral_term(self, ctx:TPTPParser.General_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#general_term.
    def exitGeneral_term(self, ctx:TPTPParser.General_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#general_data.
    def enterGeneral_data(self, ctx:TPTPParser.General_dataContext):
        pass

    # Exit a parse tree produced by TPTPParser#general_data.
    def exitGeneral_data(self, ctx:TPTPParser.General_dataContext):
        pass


    # Enter a parse tree produced by TPTPParser#general_function.
    def enterGeneral_function(self, ctx:TPTPParser.General_functionContext):
        pass

    # Exit a parse tree produced by TPTPParser#general_function.
    def exitGeneral_function(self, ctx:TPTPParser.General_functionContext):
        pass


    # Enter a parse tree produced by TPTPParser#formula_data.
    def enterFormula_data(self, ctx:TPTPParser.Formula_dataContext):
        pass

    # Exit a parse tree produced by TPTPParser#formula_data.
    def exitFormula_data(self, ctx:TPTPParser.Formula_dataContext):
        pass


    # Enter a parse tree produced by TPTPParser#general_list.
    def enterGeneral_list(self, ctx:TPTPParser.General_listContext):
        pass

    # Exit a parse tree produced by TPTPParser#general_list.
    def exitGeneral_list(self, ctx:TPTPParser.General_listContext):
        pass


    # Enter a parse tree produced by TPTPParser#general_terms.
    def enterGeneral_terms(self, ctx:TPTPParser.General_termsContext):
        pass

    # Exit a parse tree produced by TPTPParser#general_terms.
    def exitGeneral_terms(self, ctx:TPTPParser.General_termsContext):
        pass


    # Enter a parse tree produced by TPTPParser#comma_general_term.
    def enterComma_general_term(self, ctx:TPTPParser.Comma_general_termContext):
        pass

    # Exit a parse tree produced by TPTPParser#comma_general_term.
    def exitComma_general_term(self, ctx:TPTPParser.Comma_general_termContext):
        pass


    # Enter a parse tree produced by TPTPParser#name.
    def enterName(self, ctx:TPTPParser.NameContext):
        pass

    # Exit a parse tree produced by TPTPParser#name.
    def exitName(self, ctx:TPTPParser.NameContext):
        pass


    # Enter a parse tree produced by TPTPParser#atomic_word.
    def enterAtomic_word(self, ctx:TPTPParser.Atomic_wordContext):
        pass

    # Exit a parse tree produced by TPTPParser#atomic_word.
    def exitAtomic_word(self, ctx:TPTPParser.Atomic_wordContext):
        pass


    # Enter a parse tree produced by TPTPParser#atomic_defined_word.
    def enterAtomic_defined_word(self, ctx:TPTPParser.Atomic_defined_wordContext):
        pass

    # Exit a parse tree produced by TPTPParser#atomic_defined_word.
    def exitAtomic_defined_word(self, ctx:TPTPParser.Atomic_defined_wordContext):
        pass


    # Enter a parse tree produced by TPTPParser#atomic_system_word.
    def enterAtomic_system_word(self, ctx:TPTPParser.Atomic_system_wordContext):
        pass

    # Exit a parse tree produced by TPTPParser#atomic_system_word.
    def exitAtomic_system_word(self, ctx:TPTPParser.Atomic_system_wordContext):
        pass


    # Enter a parse tree produced by TPTPParser#number.
    def enterNumber(self, ctx:TPTPParser.NumberContext):
        pass

    # Exit a parse tree produced by TPTPParser#number.
    def exitNumber(self, ctx:TPTPParser.NumberContext):
        pass


    # Enter a parse tree produced by TPTPParser#file_name.
    def enterFile_name(self, ctx:TPTPParser.File_nameContext):
        pass

    # Exit a parse tree produced by TPTPParser#file_name.
    def exitFile_name(self, ctx:TPTPParser.File_nameContext):
        pass


    # Enter a parse tree produced by TPTPParser#nothing.
    def enterNothing(self, ctx:TPTPParser.NothingContext):
        pass

    # Exit a parse tree produced by TPTPParser#nothing.
    def exitNothing(self, ctx:TPTPParser.NothingContext):
        pass



del TPTPParser