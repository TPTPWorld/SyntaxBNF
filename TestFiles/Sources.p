%----Input file contains ...
     tff(person_type,type,person: $tType).
     tff(cat_type,type,cat: $tType).
     tff(loves_decl,type,loves: (person * cat) > $o).

%----ASk outputs ...
tff(the_loved_cat_decl,type,the_loved_cat: person > cat).

tff(skolemized,axiom,
   ! [P: person] :
     loves(P,the_loved_cat(P)),
   introduced(assumption,[new_symbols(skolem,[the_loved_cat]),skolemized(C)],[needs_skolemizing]) ).
