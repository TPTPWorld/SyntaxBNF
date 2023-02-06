tff(semantics,logic,
    $alethic_modal == 
      [ $constants == $rigid,
        $quantification == $constant,
        $modalities == $modal_system_T ] ).

tff(person_decl,type,person: $tType).
tff(product_decl,type,product: $tType).
tff(alex_decl,type,alex: person).
tff(chris_decl,type,chris: person).
tff(leo_decl,type,leo: product).
tff(work_hard_decl,type,work_hard: (person * product) > $o).
tff(gets_rich_decl,type,gets_rich: person > $o).

tff(work_hard_to_get_rich,axiom,
    ! [P: person] :
      ( ? [R: product] : work_hard(P,R) => {$possible} @ ( gets_rich(P) ) ) ).

tff(not_all_get_rich,axiom,
    ~ ? [P: person] : ({$necessary} @ (gets_rich(P)) ) ).

tff(alex_works_on_leo,axiom,
    work_hard(alex,leo) ).

tff(chris_works_on_leo,axiom,
    work_hard(chris,leo) ).

tff(only_alex_gets_rich,conjecture,
    ( {$possible} @ (gets_rich(alex)) & {$possible} @ (~ gets_rich(chris)) ) ).
