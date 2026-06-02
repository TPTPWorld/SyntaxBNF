# Generated from ANTLRGrammar/TPTP.g4 by ANTLR 4.13.2
from antlr4 import *
if "." in __name__:
    from .TPTPParser import TPTPParser
else:
    from TPTPParser import TPTPParser

# This class defines a complete generic visitor for a parse tree produced by TPTPParser.

class TPTPVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by TPTPParser#tptp_file.
    def visitTptp_file(self, ctx:TPTPParser.Tptp_fileContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tptp_input.
    def visitTptp_input(self, ctx:TPTPParser.Tptp_inputContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#annotated_formula.
    def visitAnnotated_formula(self, ctx:TPTPParser.Annotated_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tpi_annotated.
    def visitTpi_annotated(self, ctx:TPTPParser.Tpi_annotatedContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tpi_formula.
    def visitTpi_formula(self, ctx:TPTPParser.Tpi_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_annotated.
    def visitThf_annotated(self, ctx:TPTPParser.Thf_annotatedContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_annotated.
    def visitTff_annotated(self, ctx:TPTPParser.Tff_annotatedContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tcf_annotated.
    def visitTcf_annotated(self, ctx:TPTPParser.Tcf_annotatedContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_annotated.
    def visitFof_annotated(self, ctx:TPTPParser.Fof_annotatedContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#cnf_annotated.
    def visitCnf_annotated(self, ctx:TPTPParser.Cnf_annotatedContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#annotations.
    def visitAnnotations(self, ctx:TPTPParser.AnnotationsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#formula_role.
    def visitFormula_role(self, ctx:TPTPParser.Formula_roleContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_formula.
    def visitThf_formula(self, ctx:TPTPParser.Thf_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_logic_formula.
    def visitThf_logic_formula(self, ctx:TPTPParser.Thf_logic_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_binary_formula.
    def visitThf_binary_formula(self, ctx:TPTPParser.Thf_binary_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_binary_nonassoc.
    def visitThf_binary_nonassoc(self, ctx:TPTPParser.Thf_binary_nonassocContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_binary_assoc.
    def visitThf_binary_assoc(self, ctx:TPTPParser.Thf_binary_assocContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_or_formula.
    def visitThf_or_formula(self, ctx:TPTPParser.Thf_or_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_and_formula.
    def visitThf_and_formula(self, ctx:TPTPParser.Thf_and_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_apply_formula.
    def visitThf_apply_formula(self, ctx:TPTPParser.Thf_apply_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_unit_formula.
    def visitThf_unit_formula(self, ctx:TPTPParser.Thf_unit_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_preunit_formula.
    def visitThf_preunit_formula(self, ctx:TPTPParser.Thf_preunit_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_unitary_formula.
    def visitThf_unitary_formula(self, ctx:TPTPParser.Thf_unitary_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_quantified_formula.
    def visitThf_quantified_formula(self, ctx:TPTPParser.Thf_quantified_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_quantification.
    def visitThf_quantification(self, ctx:TPTPParser.Thf_quantificationContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_variable_list.
    def visitThf_variable_list(self, ctx:TPTPParser.Thf_variable_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_typed_variable.
    def visitThf_typed_variable(self, ctx:TPTPParser.Thf_typed_variableContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_unary_formula.
    def visitThf_unary_formula(self, ctx:TPTPParser.Thf_unary_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_prefix_unary.
    def visitThf_prefix_unary(self, ctx:TPTPParser.Thf_prefix_unaryContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_infix_unary.
    def visitThf_infix_unary(self, ctx:TPTPParser.Thf_infix_unaryContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_atomic_formula.
    def visitThf_atomic_formula(self, ctx:TPTPParser.Thf_atomic_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_plain_atomic.
    def visitThf_plain_atomic(self, ctx:TPTPParser.Thf_plain_atomicContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_defined_atomic.
    def visitThf_defined_atomic(self, ctx:TPTPParser.Thf_defined_atomicContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_defined_term.
    def visitThf_defined_term(self, ctx:TPTPParser.Thf_defined_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_defined_infix.
    def visitThf_defined_infix(self, ctx:TPTPParser.Thf_defined_infixContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_system_atomic.
    def visitThf_system_atomic(self, ctx:TPTPParser.Thf_system_atomicContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_let.
    def visitThf_let(self, ctx:TPTPParser.Thf_letContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_let_types.
    def visitThf_let_types(self, ctx:TPTPParser.Thf_let_typesContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_atom_typing_list.
    def visitThf_atom_typing_list(self, ctx:TPTPParser.Thf_atom_typing_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_let_defns.
    def visitThf_let_defns(self, ctx:TPTPParser.Thf_let_defnsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_let_defn.
    def visitThf_let_defn(self, ctx:TPTPParser.Thf_let_defnContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_let_defn_list.
    def visitThf_let_defn_list(self, ctx:TPTPParser.Thf_let_defn_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_unitary_term.
    def visitThf_unitary_term(self, ctx:TPTPParser.Thf_unitary_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_conn_term.
    def visitThf_conn_term(self, ctx:TPTPParser.Thf_conn_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_tuple.
    def visitThf_tuple(self, ctx:TPTPParser.Thf_tupleContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_formula_list.
    def visitThf_formula_list(self, ctx:TPTPParser.Thf_formula_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#comma_thf_logic_formula.
    def visitComma_thf_logic_formula(self, ctx:TPTPParser.Comma_thf_logic_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_atom_typing.
    def visitThf_atom_typing(self, ctx:TPTPParser.Thf_atom_typingContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_top_level_type.
    def visitThf_top_level_type(self, ctx:TPTPParser.Thf_top_level_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_unitary_type.
    def visitThf_unitary_type(self, ctx:TPTPParser.Thf_unitary_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_apply_type.
    def visitThf_apply_type(self, ctx:TPTPParser.Thf_apply_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_binary_type.
    def visitThf_binary_type(self, ctx:TPTPParser.Thf_binary_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_mapping_type.
    def visitThf_mapping_type(self, ctx:TPTPParser.Thf_mapping_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_xprod_type.
    def visitThf_xprod_type(self, ctx:TPTPParser.Thf_xprod_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_union_type.
    def visitThf_union_type(self, ctx:TPTPParser.Thf_union_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_subtype.
    def visitThf_subtype(self, ctx:TPTPParser.Thf_subtypeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_definition.
    def visitThf_definition(self, ctx:TPTPParser.Thf_definitionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_sequent.
    def visitThf_sequent(self, ctx:TPTPParser.Thf_sequentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_formula.
    def visitTff_formula(self, ctx:TPTPParser.Tff_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_logic_formula.
    def visitTff_logic_formula(self, ctx:TPTPParser.Tff_logic_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_binary_formula.
    def visitTff_binary_formula(self, ctx:TPTPParser.Tff_binary_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_binary_nonassoc.
    def visitTff_binary_nonassoc(self, ctx:TPTPParser.Tff_binary_nonassocContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_binary_assoc.
    def visitTff_binary_assoc(self, ctx:TPTPParser.Tff_binary_assocContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_or_formula.
    def visitTff_or_formula(self, ctx:TPTPParser.Tff_or_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_and_formula.
    def visitTff_and_formula(self, ctx:TPTPParser.Tff_and_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_unit_formula.
    def visitTff_unit_formula(self, ctx:TPTPParser.Tff_unit_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_preunit_formula.
    def visitTff_preunit_formula(self, ctx:TPTPParser.Tff_preunit_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_unitary_formula.
    def visitTff_unitary_formula(self, ctx:TPTPParser.Tff_unitary_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#txf_unitary_formula.
    def visitTxf_unitary_formula(self, ctx:TPTPParser.Txf_unitary_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_quantified_formula.
    def visitTff_quantified_formula(self, ctx:TPTPParser.Tff_quantified_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_variable_list.
    def visitTff_variable_list(self, ctx:TPTPParser.Tff_variable_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_variable.
    def visitTff_variable(self, ctx:TPTPParser.Tff_variableContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_typed_variable.
    def visitTff_typed_variable(self, ctx:TPTPParser.Tff_typed_variableContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_unary_formula.
    def visitTff_unary_formula(self, ctx:TPTPParser.Tff_unary_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_prefix_unary.
    def visitTff_prefix_unary(self, ctx:TPTPParser.Tff_prefix_unaryContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_infix_unary.
    def visitTff_infix_unary(self, ctx:TPTPParser.Tff_infix_unaryContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_atomic_formula.
    def visitTff_atomic_formula(self, ctx:TPTPParser.Tff_atomic_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_plain_atomic.
    def visitTff_plain_atomic(self, ctx:TPTPParser.Tff_plain_atomicContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_defined_atomic.
    def visitTff_defined_atomic(self, ctx:TPTPParser.Tff_defined_atomicContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_defined_plain.
    def visitTff_defined_plain(self, ctx:TPTPParser.Tff_defined_plainContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_defined_infix.
    def visitTff_defined_infix(self, ctx:TPTPParser.Tff_defined_infixContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_system_atomic.
    def visitTff_system_atomic(self, ctx:TPTPParser.Tff_system_atomicContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#txf_let.
    def visitTxf_let(self, ctx:TPTPParser.Txf_letContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#txf_let_types.
    def visitTxf_let_types(self, ctx:TPTPParser.Txf_let_typesContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_atom_typing_list.
    def visitTff_atom_typing_list(self, ctx:TPTPParser.Tff_atom_typing_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#txf_let_defns.
    def visitTxf_let_defns(self, ctx:TPTPParser.Txf_let_defnsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#txf_let_defn.
    def visitTxf_let_defn(self, ctx:TPTPParser.Txf_let_defnContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#txf_let_LHS.
    def visitTxf_let_LHS(self, ctx:TPTPParser.Txf_let_LHSContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#txf_let_defn_list.
    def visitTxf_let_defn_list(self, ctx:TPTPParser.Txf_let_defn_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#nxf_atom.
    def visitNxf_atom(self, ctx:TPTPParser.Nxf_atomContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_term.
    def visitTff_term(self, ctx:TPTPParser.Tff_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_unitary_term.
    def visitTff_unitary_term(self, ctx:TPTPParser.Tff_unitary_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#txf_tuple.
    def visitTxf_tuple(self, ctx:TPTPParser.Txf_tupleContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_arguments.
    def visitTff_arguments(self, ctx:TPTPParser.Tff_argumentsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#comma_tff_term.
    def visitComma_tff_term(self, ctx:TPTPParser.Comma_tff_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_atom_typing.
    def visitTff_atom_typing(self, ctx:TPTPParser.Tff_atom_typingContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_top_level_type.
    def visitTff_top_level_type(self, ctx:TPTPParser.Tff_top_level_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_non_atomic_type.
    def visitTff_non_atomic_type(self, ctx:TPTPParser.Tff_non_atomic_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tf1_quantified_type.
    def visitTf1_quantified_type(self, ctx:TPTPParser.Tf1_quantified_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_monotype.
    def visitTff_monotype(self, ctx:TPTPParser.Tff_monotypeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_unitary_type.
    def visitTff_unitary_type(self, ctx:TPTPParser.Tff_unitary_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_atomic_type.
    def visitTff_atomic_type(self, ctx:TPTPParser.Tff_atomic_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_type_arguments.
    def visitTff_type_arguments(self, ctx:TPTPParser.Tff_type_argumentsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_mapping_type.
    def visitTff_mapping_type(self, ctx:TPTPParser.Tff_mapping_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_xprod_type.
    def visitTff_xprod_type(self, ctx:TPTPParser.Tff_xprod_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#txf_tuple_type.
    def visitTxf_tuple_type(self, ctx:TPTPParser.Txf_tuple_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_type_list.
    def visitTff_type_list(self, ctx:TPTPParser.Tff_type_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_subtype.
    def visitTff_subtype(self, ctx:TPTPParser.Tff_subtypeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#txf_definition.
    def visitTxf_definition(self, ctx:TPTPParser.Txf_definitionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#txf_sequent.
    def visitTxf_sequent(self, ctx:TPTPParser.Txf_sequentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#nhf_long_connective.
    def visitNhf_long_connective(self, ctx:TPTPParser.Nhf_long_connectiveContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#nhf_parameter_list.
    def visitNhf_parameter_list(self, ctx:TPTPParser.Nhf_parameter_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#nhf_parameter.
    def visitNhf_parameter(self, ctx:TPTPParser.Nhf_parameterContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#nhf_key_pair.
    def visitNhf_key_pair(self, ctx:TPTPParser.Nhf_key_pairContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#nxf_long_connective.
    def visitNxf_long_connective(self, ctx:TPTPParser.Nxf_long_connectiveContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#nxf_parameter_list.
    def visitNxf_parameter_list(self, ctx:TPTPParser.Nxf_parameter_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#nxf_parameter.
    def visitNxf_parameter(self, ctx:TPTPParser.Nxf_parameterContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#nxf_key_pair.
    def visitNxf_key_pair(self, ctx:TPTPParser.Nxf_key_pairContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#ntf_connective_name.
    def visitNtf_connective_name(self, ctx:TPTPParser.Ntf_connective_nameContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#ntf_defined_connective.
    def visitNtf_defined_connective(self, ctx:TPTPParser.Ntf_defined_connectiveContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#ntf_index.
    def visitNtf_index(self, ctx:TPTPParser.Ntf_indexContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#ntf_short_connective.
    def visitNtf_short_connective(self, ctx:TPTPParser.Ntf_short_connectiveContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tcf_formula.
    def visitTcf_formula(self, ctx:TPTPParser.Tcf_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tcf_logic_formula.
    def visitTcf_logic_formula(self, ctx:TPTPParser.Tcf_logic_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tcf_quantified_formula.
    def visitTcf_quantified_formula(self, ctx:TPTPParser.Tcf_quantified_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_formula.
    def visitFof_formula(self, ctx:TPTPParser.Fof_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_logic_formula.
    def visitFof_logic_formula(self, ctx:TPTPParser.Fof_logic_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_binary_formula.
    def visitFof_binary_formula(self, ctx:TPTPParser.Fof_binary_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_binary_nonassoc.
    def visitFof_binary_nonassoc(self, ctx:TPTPParser.Fof_binary_nonassocContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_binary_assoc.
    def visitFof_binary_assoc(self, ctx:TPTPParser.Fof_binary_assocContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_or_formula.
    def visitFof_or_formula(self, ctx:TPTPParser.Fof_or_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_and_formula.
    def visitFof_and_formula(self, ctx:TPTPParser.Fof_and_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_unary_formula.
    def visitFof_unary_formula(self, ctx:TPTPParser.Fof_unary_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_infix_unary.
    def visitFof_infix_unary(self, ctx:TPTPParser.Fof_infix_unaryContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_unit_formula.
    def visitFof_unit_formula(self, ctx:TPTPParser.Fof_unit_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_unitary_formula.
    def visitFof_unitary_formula(self, ctx:TPTPParser.Fof_unitary_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_quantified_formula.
    def visitFof_quantified_formula(self, ctx:TPTPParser.Fof_quantified_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_variable_list.
    def visitFof_variable_list(self, ctx:TPTPParser.Fof_variable_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_atomic_formula.
    def visitFof_atomic_formula(self, ctx:TPTPParser.Fof_atomic_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_plain_atomic_formula.
    def visitFof_plain_atomic_formula(self, ctx:TPTPParser.Fof_plain_atomic_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_defined_atomic_formula.
    def visitFof_defined_atomic_formula(self, ctx:TPTPParser.Fof_defined_atomic_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_defined_plain_formula.
    def visitFof_defined_plain_formula(self, ctx:TPTPParser.Fof_defined_plain_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_defined_infix_formula.
    def visitFof_defined_infix_formula(self, ctx:TPTPParser.Fof_defined_infix_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_system_atomic_formula.
    def visitFof_system_atomic_formula(self, ctx:TPTPParser.Fof_system_atomic_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_plain_term.
    def visitFof_plain_term(self, ctx:TPTPParser.Fof_plain_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_defined_term.
    def visitFof_defined_term(self, ctx:TPTPParser.Fof_defined_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_defined_atomic_term.
    def visitFof_defined_atomic_term(self, ctx:TPTPParser.Fof_defined_atomic_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_defined_plain_term.
    def visitFof_defined_plain_term(self, ctx:TPTPParser.Fof_defined_plain_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_system_term.
    def visitFof_system_term(self, ctx:TPTPParser.Fof_system_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_arguments.
    def visitFof_arguments(self, ctx:TPTPParser.Fof_argumentsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_term.
    def visitFof_term(self, ctx:TPTPParser.Fof_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_function_term.
    def visitFof_function_term(self, ctx:TPTPParser.Fof_function_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_sequent.
    def visitFof_sequent(self, ctx:TPTPParser.Fof_sequentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_formula_tuple.
    def visitFof_formula_tuple(self, ctx:TPTPParser.Fof_formula_tupleContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_formula_tuple_list.
    def visitFof_formula_tuple_list(self, ctx:TPTPParser.Fof_formula_tuple_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#comma_fof_logic_formula.
    def visitComma_fof_logic_formula(self, ctx:TPTPParser.Comma_fof_logic_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#cnf_formula.
    def visitCnf_formula(self, ctx:TPTPParser.Cnf_formulaContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#cnf_disjunction.
    def visitCnf_disjunction(self, ctx:TPTPParser.Cnf_disjunctionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#cnf_literal.
    def visitCnf_literal(self, ctx:TPTPParser.Cnf_literalContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_quantifier.
    def visitThf_quantifier(self, ctx:TPTPParser.Thf_quantifierContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#thf_unary_connective.
    def visitThf_unary_connective(self, ctx:TPTPParser.Thf_unary_connectiveContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#th0_quantifier.
    def visitTh0_quantifier(self, ctx:TPTPParser.Th0_quantifierContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#type_quantifier.
    def visitType_quantifier(self, ctx:TPTPParser.Type_quantifierContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#subtype_sign.
    def visitSubtype_sign(self, ctx:TPTPParser.Subtype_signContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_unary_connective.
    def visitTff_unary_connective(self, ctx:TPTPParser.Tff_unary_connectiveContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#tff_quantifier.
    def visitTff_quantifier(self, ctx:TPTPParser.Tff_quantifierContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#fof_quantifier.
    def visitFof_quantifier(self, ctx:TPTPParser.Fof_quantifierContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#nonassoc_connective.
    def visitNonassoc_connective(self, ctx:TPTPParser.Nonassoc_connectiveContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#assoc_connective.
    def visitAssoc_connective(self, ctx:TPTPParser.Assoc_connectiveContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#unary_connective.
    def visitUnary_connective(self, ctx:TPTPParser.Unary_connectiveContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#gentzen_arrow.
    def visitGentzen_arrow(self, ctx:TPTPParser.Gentzen_arrowContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#assignment.
    def visitAssignment(self, ctx:TPTPParser.AssignmentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#identical.
    def visitIdentical(self, ctx:TPTPParser.IdenticalContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#type_constant.
    def visitType_constant(self, ctx:TPTPParser.Type_constantContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#type_functor.
    def visitType_functor(self, ctx:TPTPParser.Type_functorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#defined_type.
    def visitDefined_type(self, ctx:TPTPParser.Defined_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#atom.
    def visitAtom(self, ctx:TPTPParser.AtomContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#untyped_atom.
    def visitUntyped_atom(self, ctx:TPTPParser.Untyped_atomContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#defined_infix_pred.
    def visitDefined_infix_pred(self, ctx:TPTPParser.Defined_infix_predContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#infix_equality.
    def visitInfix_equality(self, ctx:TPTPParser.Infix_equalityContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#infix_inequality.
    def visitInfix_inequality(self, ctx:TPTPParser.Infix_inequalityContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#constant.
    def visitConstant(self, ctx:TPTPParser.ConstantContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#functor.
    def visitFunctor(self, ctx:TPTPParser.FunctorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#defined_constant.
    def visitDefined_constant(self, ctx:TPTPParser.Defined_constantContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#defined_functor.
    def visitDefined_functor(self, ctx:TPTPParser.Defined_functorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#system_constant.
    def visitSystem_constant(self, ctx:TPTPParser.System_constantContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#system_functor.
    def visitSystem_functor(self, ctx:TPTPParser.System_functorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#th1_defined_term.
    def visitTh1_defined_term(self, ctx:TPTPParser.Th1_defined_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#defined_term.
    def visitDefined_term(self, ctx:TPTPParser.Defined_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#variable.
    def visitVariable(self, ctx:TPTPParser.VariableContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#source.
    def visitSource(self, ctx:TPTPParser.SourceContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#sources.
    def visitSources(self, ctx:TPTPParser.SourcesContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#dag_source.
    def visitDag_source(self, ctx:TPTPParser.Dag_sourceContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#inference_record.
    def visitInference_record(self, ctx:TPTPParser.Inference_recordContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#inference_rule.
    def visitInference_rule(self, ctx:TPTPParser.Inference_ruleContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#internal_source.
    def visitInternal_source(self, ctx:TPTPParser.Internal_sourceContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#intro_type.
    def visitIntro_type(self, ctx:TPTPParser.Intro_typeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#external_source.
    def visitExternal_source(self, ctx:TPTPParser.External_sourceContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#file_source.
    def visitFile_source(self, ctx:TPTPParser.File_sourceContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#file_info.
    def visitFile_info(self, ctx:TPTPParser.File_infoContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#theory.
    def visitTheory(self, ctx:TPTPParser.TheoryContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#theory_name.
    def visitTheory_name(self, ctx:TPTPParser.Theory_nameContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#creator_source.
    def visitCreator_source(self, ctx:TPTPParser.Creator_sourceContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#creator_name.
    def visitCreator_name(self, ctx:TPTPParser.Creator_nameContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#parents.
    def visitParents(self, ctx:TPTPParser.ParentsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#parent_list.
    def visitParent_list(self, ctx:TPTPParser.Parent_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#comma_parent_info.
    def visitComma_parent_info(self, ctx:TPTPParser.Comma_parent_infoContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#parent_info.
    def visitParent_info(self, ctx:TPTPParser.Parent_infoContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#parent_details.
    def visitParent_details(self, ctx:TPTPParser.Parent_detailsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#optional_info.
    def visitOptional_info(self, ctx:TPTPParser.Optional_infoContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#useful_info.
    def visitUseful_info(self, ctx:TPTPParser.Useful_infoContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#include.
    def visitInclude(self, ctx:TPTPParser.IncludeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#include_optionals.
    def visitInclude_optionals(self, ctx:TPTPParser.Include_optionalsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#formula_selection.
    def visitFormula_selection(self, ctx:TPTPParser.Formula_selectionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#name_list.
    def visitName_list(self, ctx:TPTPParser.Name_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#space_name.
    def visitSpace_name(self, ctx:TPTPParser.Space_nameContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#general_term.
    def visitGeneral_term(self, ctx:TPTPParser.General_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#general_data.
    def visitGeneral_data(self, ctx:TPTPParser.General_dataContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#general_function.
    def visitGeneral_function(self, ctx:TPTPParser.General_functionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#formula_data.
    def visitFormula_data(self, ctx:TPTPParser.Formula_dataContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#general_list.
    def visitGeneral_list(self, ctx:TPTPParser.General_listContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#general_terms.
    def visitGeneral_terms(self, ctx:TPTPParser.General_termsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#comma_general_term.
    def visitComma_general_term(self, ctx:TPTPParser.Comma_general_termContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#name.
    def visitName(self, ctx:TPTPParser.NameContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#atomic_word.
    def visitAtomic_word(self, ctx:TPTPParser.Atomic_wordContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#atomic_defined_word.
    def visitAtomic_defined_word(self, ctx:TPTPParser.Atomic_defined_wordContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#atomic_system_word.
    def visitAtomic_system_word(self, ctx:TPTPParser.Atomic_system_wordContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#number.
    def visitNumber(self, ctx:TPTPParser.NumberContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#file_name.
    def visitFile_name(self, ctx:TPTPParser.File_nameContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by TPTPParser#nothing.
    def visitNothing(self, ctx:TPTPParser.NothingContext):
        return self.visitChildren(ctx)



del TPTPParser