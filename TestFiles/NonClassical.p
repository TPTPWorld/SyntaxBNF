thf(simple_s5,logic,(
    $modal ==
      [ $logicfile == 'LOG003_1.l',
        $constants == $rigid,
        $quantification == $constant,
        $consequence == $global,
        $modalities == ^ [X: $i] : ($R @ X @ X) ] )).

ZZZ
thf(a0,axiom,{$necessary} @ p).
thf(a1,axiom,{$necessary:#7} @ p).
thf(a2,axiom,{$necessary:#7,$a := b} @ p).
thf(a3,axiom,[.] @ p).
thf(a4,axiom,[#7] @ p).
tff(b0,axiom,{$necessary}(p)).
tff(b1,axiom,{$necessary:#7}(p)).
tff(b2,axiom,{$necessary:#7,$a := b}(p)).
tff(b3,axiom,[.](p)).
tff(b4,axiom,[#7](p)).

thf(c1,axiom,(
    {$knows:#1} @ {$common:$group:=[2,3,4]} @ something_commonly_known_by_agents_2_3_and_4 )).
tff(c2,axiom,(
    {$knows:#1}({$common:$group:=[2,3,4]}(something_commonly_known_by_agents_2_3_and_4)) )).


    tff(pigs_might_fly_type,type,(
        pigs_might_fly: $o )).

    tff(no_flying_pigs,axiom,(
        ~ ( {$possible}(pigs_might_fly) ) )).

    tff(short_no_flying_pigs,axiom,(
        ~ ( <.>(pigs_might_fly) ) )).

    tff(an_individual_type,type,(
        me: $i )).

    tff(for_me_it_is_possible,axiom,(
        {$possible:#me}(pigs_might_fly) )).

    tff(short_for_me_it_is_possible,axiom,(
        <#me>(pigs_might_fly) )).

    tff(for_me_somthing_is_possible,axiom,(
        ? [P: $o] : {$possible:#me}(P) )).

    tff(short_for_me_somthing_is_possible,axiom,(
        ? [P: $o] : <#me>(P) )).

    tff(some_individual_says_flying_pigs,axiom,(
        ? [X: $i] : {$possible:#X}(pigs_might_fly) )).

    tff(short_some_individual_says_flying_pigs,axiom,(
        ? [X: $i] : <#X>(pigs_might_fly) )).

    tff(agent_type,type,(
        agent: $tType )).

    tff(archer_agent,type,(
        archer: agent )).

    tff(archer_says_no_flying_pigs,axiom,(
        ~ ( {$possible:#archer}(pigs_might_fly) ) )).

    tff(short_archer_says_no_flying_pigs,axiom,(
        ~ ( <#archer>(pigs_might_fly) ) )).

    tff(all_agents_say_flying_pigs,axiom,(
        ! [A: agent] : {$necessary:#A}(pigs_might_fly) )).

    tff(short_all_agents_say_flying_pigs,axiom,(
        ! [A: agent] : [#A](pigs_might_fly) )).

    tff(all_agents_say_everything,axiom,(
        ! [A: agent,P: $o] : {$necessary:#A}(P) )).

    tff(short_all_agents_say_everything,axiom,(
        ! [A: agent,P: $o] : [#A](P) )).


    thf(pigs_might_fly_type,type,(
        pigs_might_fly: $o )).

    thf(no_flying_pigs,axiom,(
        ~ ( {$possible} @ pigs_might_fly ) )).

    thf(short_no_flying_pigs,axiom,(
        ~ ( <.> @ pigs_might_fly ) )).

    thf(an_individual_type,type,(
        me: $i )).

    thf(for_me_it_is_possible,axiom,(
        {$possible:#me} @ pigs_might_fly )).

    thf(short_for_me_it_is_possible,axiom,(
        <#me> @ pigs_might_fly )).

    thf(for_me_somthing_is_possible,axiom,(
        ? [P: $o] : {$possible:#me} @ P )).

    thf(short_for_me_somthing_is_possible,axiom,(
        ? [P: $o] : <#me> @ P )).

    thf(some_individual_says_flying_pigs,axiom,(
        ? [X: $i] : {$possible:#X} @ pigs_might_fly )).

    thf(short_some_individual_says_flying_pigs,axiom,(
        ? [X: $i] : <#X> @ pigs_might_fly )).

    thf(agent_type,type,(
        agent: $tType )).

    thf(archer_says_no_flying_pigs,axiom,(
        ~ ( {$possible:#archer} @ pigs_might_fly ) )).

    thf(short_archer_says_no_flying_pigs,axiom,(
        ~ ( <#archer> @ pigs_might_fly ) )).

    thf(all_agents_say_flying_pigs,axiom,(
        ! [A: agent] : {$necessary:#A} @ pigs_might_fly )).

    thf(short_all_agents_say_flying_pigs,axiom,(
        ! [A: agent] : [#A] @ pigs_might_fly )).

    thf(all_agents_say_everything,axiom,(
        ! [A: agent,P: $o] : {$necessary:#A} @ P )).

    thf(short_all_agents_say_everything,axiom,(
        ! [A: agent,P: $o] : [#A] @ P )).

tff(t1,axiom,
    {.}(p) ).
tff(t1,axiom,
    (.)(p) ).
tff(t1,axiom,
    {#7}(p) ).
tff(t1,axiom,
    (#7)(p) ).
