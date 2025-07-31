% SZS status Success for /home/tptp/Systems/IIV---0.0/TestFiles/Garfield.s
% SZS output start ListOfFormulae for /home/tptp/Systems/IIV---0.0/TestFiles/Garfield.s
fof('$o.',axiom,(
    $o ),
    introduced(language,[ level(0) ],[ ]),
    []).

fof(cat,axiom,(
    cat ),
    introduced(language,[ level(0) ],[ ]),
    []).

fof(human,axiom,(
    human ),
    introduced(language,[ level(0) ],[ ]),
    []).

thf('$o.owns',negated_conjecture,(
    owns: ( human * cat ) > $o ),
    inference(interpretation,[ level(1) ],[ '$o.' ]),
    []).

tcf('$o.owns.d_jon',plain,(
    d_jon: d_human ),
    inference(interpretation,[ level(2) ],[ '$o.owns' ]),
    []).

tcf('$o.owns.d_jon.d_arlene',plain,(
    d_arlene: d_cat ),
    inference(interpretation,[ level(3) ],[ '$o.owns.d_jon' ]),
    []).

tcf('$o.owns.d_jon.d_garfield',plain,(
    d_garfield: d_cat ),
    inference(interpretation,[ level(3) ],[ '$o.owns.d_jon' ]),
    []).

tcf('$o.owns.d_jon.d_nermal',plain,(
    d_nermal: d_cat ),
    inference(interpretation,[ level(3) ],[ '$o.owns.d_jon' ]),
    []).

thf('cat.arlene',negated_conjecture,(
    arlene: cat ),
    inference(interpretation,[ level(1) ],[ cat ]),
    []).

thf('cat.garfield',negated_conjecture,(
    garfield: cat ),
    inference(interpretation,[ level(1) ],[ cat ]),
    []).

thf('cat.loves',negated_conjecture,(
    loves: cat > cat ),
    inference(interpretation,[ level(1) ],[ cat ]),
    []).

thf('cat.nermal',negated_conjecture,(
    nermal: cat ),
    inference(interpretation,[ level(1) ],[ cat ]),
    []).

tcf('cat.loves.d_arlene',plain,(
    d_arlene: d_cat ),
    inference(interpretation,[ level(2) ],[ 'cat.loves' ]),
    []).

tcf('cat.loves.d_garfield',plain,(
    d_garfield: d_cat ),
    inference(interpretation,[ level(2) ],[ 'cat.loves' ]),
    []).

tcf('cat.loves.d_nermal',plain,(
    d_nermal: d_cat ),
    inference(interpretation,[ level(2) ],[ 'cat.loves' ]),
    []).

thf('human.jon',negated_conjecture,(
    jon: human ),
    inference(interpretation,[ level(1) ],[ human ]),
    []).

tcf('$true.$o',conjecture,(
    $true ),
    inference(interpretation,[ level(4) ],[ '$o.owns.d_jon.d_garfield' ]),
    []).

tcf('$false.$o',conjecture,(
    $false ),
    inference(interpretation,[ level(4) ],[ '$o.owns.d_jon.d_arlene', '$o.owns.d_jon.d_nermal' ]),
    []).

tcf('d_jon.d_human',conjecture,(
    d_jon: d_human ),
    inference(interpretation,[ level(4) ],[ 'human.jon' ]),
    []).

tcf('d_garfield.d_cat',conjecture,(
    d_garfield: d_cat ),
    inference(interpretation,[ level(4) ],[ 'cat.garfield', 'cat.loves.d_garfield', 'cat.loves.d_arlene', 'cat.loves.d_nermal' ]),
    []).

tcf('d_arlene.d_cat',conjecture,(
    d_arlene: d_cat ),
    inference(interpretation,[ level(4) ],[ 'cat.arlene' ]),
    []).

tcf('d_nermal.d_cat',conjecture,(
    d_nermal: d_cat ),
    inference(interpretation,[ level(4) ],[ 'cat.nermal' ]),
    []).

fof('$o.d',axiom,(
    $o ),
    inference(type,[ level(5) ],[ '$false.$o', '$true.$o' ]),
    []).

fof(d_cat,axiom,(
    d_cat ),
    inference(type,[ level(5) ],[ 'd_arlene.d_cat', 'd_garfield.d_cat', 'd_nermal.d_cat' ]),
    []).

fof(d_human,axiom,(
    d_human ),
    inference(type,[ level(5) ],[ 'd_jon.d_human' ]),
    []).

% SZS output end ListOfFormulae for /home/tptp/Systems/IIV---0.0/TestFiles/Garfield.s
