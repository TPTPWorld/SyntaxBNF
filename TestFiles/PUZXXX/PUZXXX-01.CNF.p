%----CNF
cnf(odie_is_a_dog,axiom,
    dog(odie) ).

cnf(jon_owns_odie,axiom,
    owner_of(odie) = jon ).

cnf(all_owners_are_human,axiom,
    ( ~ dog(D)
    | human(owner_of(D)) ) ).

cnf(odie_bit_jon,axiom,
    bit(odie,jon) ).

cnf(another_dog,axiom,
    dog(esk1_0) ).

cnf(not_odie,axiom,
    esk1_0 != odie ).

cnf(not_owned_by_jon,axiom,
    jon != owner_of(esk1_0) ).

cnf(bit_jon,axiom,
    bit(esk1_0,jon) ).

cnf(hate_the_biter,axiom,
    ( ~ dog(D)
    | ~ human(H)
    | H = owner_of(D)
    | ~ bit(D,H)
    | hates(H,owner_of(D)) ) ).

cnf(jon_hates_another,negated_conjecture,
    ( ~ human(H)
    | H = jon
    | ~ hates(jon,H) ) ).
