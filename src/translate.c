/*ANNA MAKRIDOU 
ASSIGNMENT 1 AM:4934 
translate.c*/

#include <stdio.h>

/*Opws zhteitai sthn ekfwnhsh, ginetai xrhsh tou define gia poly suxna emfanizomenes
times pou vohthoun sthn kaluterh anagnwsh tou kwdika tou state machine. Epishs ginetai
xrhsh enos enum tupou gia thn anaparastash twn katastasewn*/

/*difthoggoi*/
#define B 66
#define D 68
#define b 98
#define d 100

/*ellhnika grammata*/
#define Mi 204
#define Ni 205
#define Pi 208
#define Taf 212
#define mi 236
#define ni 237
#define pi 240
#define taf 244

/*agglika grammata*/
#define Em 77
#define En 78
#define em 109
#define en 110

enum state {start,Sn,St,Sm,Sp,SN,ST,SM,SP}; 

/*Dhlwsh sunarthsewn pou tha ulopoihthoun epeita gia thn ulopoihsh ths askhshs*/

void changeLetter(int c, int M[255][3]);
void initialize(int M[255][3]);
void staysTheSame(int c);
void firstCase(int c,int M[255][3]);
void secondCase(int c,int M[255][3]);
void thirdCase(int c,int M[255][3]);
enum state stateMachine(int c, enum state s,int M[255][3]);
enum state stateStart(int c, enum state s,int M[255][3]);
enum state stateSN(int c, enum state s,int M[255][3]);
enum state stateSn(int c, enum state s,int M[255][3]);
enum state stateST(int c, enum state s,int M[255][3]);
enum state stateSt(int c, enum state s,int M[255][3]);
enum state stateSM(int c, enum state s,int M[255][3]);
enum state stateSm(int c, enum state s,int M[255][3]);
enum state stateSP(int c, enum state s,int M[255][3]);
enum state stateSp(int c, enum state s,int M[255][3]);

/*H sunarthsh main pairnei input apo ena arxeio.
Otan ekteloume thn entolh a.out < testfile.7 diavazei enan enan
tous xarakthres tou arxeiou kai kalwntas to state machine antikathista
katallhla to kathe xarakthra apo to iso8859-7 se xarakthres tou iso8859-1
opws tha doume parakatw analutikotera*/
int main(void) {
    int M[255][3],c;        /*o tupos tou c einai int giati h getchat einai typou int.*/
    enum state s=start;    /*h mhxanh ksekinaei apo thn arxikh katastash*/
    initialize(M);         /*kalw th sunarthsh arxikopoihshs gia ta mappings*/
    while((c=getchar())!=EOF) {         /*mexri na ftasw sto telos tou arxeiou*/
        s=stateMachine(c,s,M);    
    }                   /*gia kathe xarakthra tou arxeiou kalw to state machine*/
    return 0; 
}

/*Sunarthsh arxikopoihshs domhs.
O pinakas exei treis sthles gia na kaluptei kathe periptwsh, epeidh sth periptwsh twn
dialutikwn me tono o enas xarakthras antikathistatai me 3 
(neos xarakthras,mono quote, diplo quote)*/
void initialize(int M[255][3]) {    

    /*Case1: oi aploi xarakthres antikathistantai apo enan xarakthra,
    ektos apo to ps,ks pou antikathistantai apo duo xarakthres ara tha xreiastoume
    kai th deuterh sthlh se autes tis 2 periptwseis mono.
    Xrhsimopoiw enan pinaka 255 thesewn epeidh to iso8859-7 ftanei ws to 254 kai theloume
    tha xrhsimopoihsoume to xarakthra pou theloume na antikatasthsoume ws 
    index se enan pinaka. To stoixeio tou index autou antistoixei ston xarakthra 
    tou iso8859-1 pou antikathista to xarakthra tou iso8859-7.
    INDEX=GREEK LETTER
    VALUE=ENGLISH LETTER
    */

    M[193][0]=65;   
    M[194][0]=86;  
    M[195][0]=71;
    M[196][0]=68;   
    M[197][0]=69;   
    M[198][0]=90;       
    M[199][0]=72;
    M[200][0]=56;
    M[201][0]=73;
    M[202][0]=75;
    M[203][0]=76;
    M[204][0]=77;
    M[Ni][0]=78;
    M[206][0]=75;
    M[207][0]=79;
    M[208][0]=80;
    M[209][0]=82;
    M[211][0]=83;
    M[212][0]=84;
    M[213][0]=89;
    M[214][0]=70;
    M[215][0]=88;
    M[216][0]=80;
    M[217][0]=87;
    M[225][0]=97;  
    M[226][0]=118;   
    M[227][0]=103;  
    M[228][0]=100; 
    M[229][0]=101;   
    M[230][0]=122;
    M[231][0]=104;
    M[232][0]=56;
    M[233][0]=105;
    M[234][0]=107;
    M[235][0]=108;
    M[236][0]=109;
    M[237][0]=110;
    M[238][0]=107;
    M[239][0]=111;
    M[240][0]=112;
    M[241][0]=114;
    M[242][0]=115;
    M[243][0]=115;
    M[244][0]=116;
    M[245][0]=121;
    M[246][0]=102;
    M[247][0]=120;
    M[248][0]=112;
    M[249][0]=119;

    /*EKSAIRESEIS: PERIPTWSH KS,PS: xreiazomai mia epipleon sthlh gia to S
    afou o pinakas einai tupou char xwraei mono 1 Byte ana sthlh*/

    M[206][1]=83;
    M[216][1]=83;
    M[238][1]=115;
    M[248][1]=115;
  
    /*Case2:Oi xarakthres me tonous antikathistantai apo xarakthres me ena quote
    To quote einai to noumero 39 sto iso. sta kefalaia grammata to quote
    mpainei prin ton xarakthra, ara tha mpei sth prwth sthlh tou pinaka to quote kai
    sth deuterh o xarakthras tou iso8859-1. Antithetws gia ta mikra grammata to quote
    mpainei meta ton xarakthra ara sth prwth sthlh tou pinaka mpainei to gramma kai sth deuterh
    to quote*/

    M[182][0]=39; 
    M[184][0]=39;  
    M[185][0]=39;   
    M[186][0]=39;  
    M[188][0]=39;  
    M[190][0]=39;
    M[191][0]=39;
    M[220][0]=97;
    M[221][0]=101;
    M[222][0]=104;
    M[223][0]=105;
    M[252][0]=111;
    M[254][0]=119;
    M[253][0]=121;
    M[182][1]=65;   
    M[184][1]=69;   
    M[185][1]=72;   
    M[186][1]=73;   
    M[188][1]=79;   
    M[190][1]=89;
    M[191][1]=87;
    M[220][1]=39;
    M[221][1]=39;
    M[222][1]=39;
    M[223][1]=39;
    M[252][1]=39;
    M[254][1]=39;
    M[253][1]=39;

    /*Case3:oi xarakthres pou exoun dialutika h tonous me dialutika. 
    1)Gia tous xarakthres pou exoun mono dialutika antikathistame to xarakthra
    me ton antistoixo sto iso8859-1 kai me ena diplo quote dipla tou(arithmos 34).
    2)An uparxei kai tonos kai dialutika tote antikathistatai me to neo gramma,
    to mono quote(39) kai to diplo quote(34). Gia na ulopoihsoyme auto
    xrhsimopoioume 3 sthles pinakwn. H kathe sthlh periexei antistoixa to gramma,
    to mono quote, kai to diplo quote(ean xreiazetai)*/

    M[250][0]=105;  
    M[251][0]=121;  
    M[192][0]=105; 
    M[224][0]=121; 
    M[218][0]=73;
    M[219][0]=89;
    M[250][1]=34;   
    M[251][1]=34;  
    M[192][1]=39;  
    M[224][1]=39;  
    M[218][1]=73;   
    M[219][1]=89;
    M[192][2]=34;   
    M[224][2]=34;  
}

/*H sunarthsh auth elegxei an to c einai kapoios agglikos xarakthras pou den mas endiaferei
na allaksoume kai paramenei idios, sumperilamvanei kai px to newline(10), to space(32) pou
den allazoun stis antistoixies. Sth periptwsh auth tupwnei to xarakthra pou diavasthke opws
einai*/
void staysTheSame(int c) {    
    if((c>=0 && c<=181) || (c==183) || (c==187) || (c==189)) {
        putchar(c);
    }
}

/*Sthn aplh periptwsh ektupwnw th prwth sthlh tou pinaka pou periexei to gramma pou
antistoixei sto index c pou diavazoume apo to file. diakrinoume omws 4 xwristes periptwseis
gia ta mikra kai kefalaia grammata KSI,ksi,PSI,psi ta opoia apotelountai apo duo xarakthres,
oi opoioi exoun topotheththei stis prwtes 2 sthles
*/
void firstCase(int c,int M[255][3]) {
    if(c==206) {                /*gramma KSI->KS*/
        putchar(M[c][0]);       /*ektupwnw to K kai to S pou exw apothikeusei stis prwtes 2 sthles*/
        putchar(M[c][1]);
    }   
    else if(c==216) {           /*gramma PSI->ps*/
        putchar(M[c][0]);
        putchar(M[c][1]);
    }
    else if(c==238) {             /*gramma ksi->ks*/
        putchar(M[c][0]);
        putchar(M[c][1]);
    }
    else if(c==248) {               /*gramma psi->ps*/
        putchar(M[c][0]);
        putchar(M[c][1]);
    }
    else {
        putchar(M[c][0]);       /*se kathe allh periptwsh, ektos dhl. tou ks,ps,KS,PS*/
    }                           /*tupwnw th prwth sthlh*/
}

/*h deuterh periptwsh einai arketa aplh kathws tupwnw tis 2 prwtes sthles
gia ton xarakthra me tono, mia sthlh periexei ton neo xarakthra kai h allh
sthlh periexei to quote*/
void secondCase(int c,int M[255][3]){
    putchar(M[c][0]);
    putchar(M[c][1]);
}

/*h trith periptwsh einai me tous tonous kai ta dialutika h ta sketa dialutika*/
void thirdCase(int c,int M[255][3]) {
    if(c==192 || c==224) {      /*an h eisodos einai giwta/upsilon me tono kai dialutika*/
        putchar(M[c][0]);       /*tote tupwnoume kai tis 3 sthles. opws anaferthike parapanw*/
        putchar(M[c][1]);       /*h prwth sthlh periexei to neo gramma, h deuterh to mono quote, h trith to diplo quote*/
        putchar(M[c][2]);       
    }
    else {                      /*an den exei tono tote tupwnwnw tis prwtes 2 sthles pou periexoun*/
        putchar(M[c][0]);       /*to neo gramma kai to diplo quote*/
        putchar(M[c][1]);
    }
}

/*h parakatw sunarthsh kaleitai gia na mporesei na pragmatopoihthei
h antikatastash pou orisame me tis parapanw sunarthseis.
kaleitai se kathe periptwsh, ektos ean exoume tous difthoggous pou
xreiazontai eidikh metaxeirish mesw tou state machine*/
void changeLetter(int c,int M[255][3]){
    if((c>=193 && c<=217) || (c>=225 && c<=249)) {
        firstCase(c,M);            /*ta eurh auta ekfrazoun ta kefalaia/peza ellhnika*/   
    }                                   /*grammata xwris tono ara kaloume th 1h periptwsh*/
    if((c==182 || (c>=184 && c<=186) || c==188 || c==190 
    || c==191 || (c>=220 && c<=223) || (c>=252 && c<=254))){
        secondCase(c,M);      /*ta eurh auta ekfrazoun ta kefalaia/peza tonismena grammata*/      
    }                           /*ara kaloume th sunarthsh ths deuterhs periptwshs*/
    if(c==192 || c==218 || c==219 || c==224 || c==250 || c==251){
        thirdCase(c,M);         /*ta eurh auta ekfrazoun ta grammata me tono - dialutika*/
    }                           /*ara kaloume th sunarthsh ths triths periptwshs*/
    else staysTheSame(c);       
}   /*an o xarakthras pou diavasame den empimptei se kanena euros tote paramenei idios*/

/*afou etoimasame tis prwtes treis periptwseis, apo auto to shmeio kai epeita
asxoloumaste me to state machine pou ruthmizei tis ekshs periptwseis
1)Nt->D
2)NT->D
3)nT->d
4)nt->d
5)Mp->B
6)MP->B
7)mP->b
8)mp->b
Exoume 8 periptwseis kai tha xreiastoume 8 diaforetikes katastaseis gia kathe
gramma. Dhladh mia katastash gia to N(SN),M(SM),T(ST),P(SP),n(Sn),m(Sm),t(St),p(Sp)
kai mia akomh katastash h opoia tha einai h arxikh katastash(start)*/
enum state stateMachine(int c, enum state s,int M[255][3]){
    /*gia kathe katastash kaloume thn antistoixh sunarthsh ths*/
    switch(s){
        case start: 
            s=stateStart(c,s,M);
            break;
        case SN: 
            s=stateSN(c,s,M);
            break;
        case Sn: 
            s=stateSn(c,s,M);
            break;
        case ST: 
            s=stateST(c,s,M);
            break;
        case St: 
            s=stateSt(c,s,M);
            break;
        case SM: 
            s=stateSM(c,s,M);
            break;
        case Sm: 
            s=stateSm(c,s,M);
            break;
        case SP: 
            s=stateSP(c,s,M);
            break;
        case Sp: 
            s=stateSp(c,s,M);
            break;
    }
    return s; /*epistrefoume th nea katastash gia na enhmerwthei to state machine*/
}

/*prwth katastash: start-arxikh katastash.
An mas dothei apto file to gramma M/m/N/n den mporoume
na to antikatasthsoume, giati den kseroume an akolouthoun ta
grammata t/T/P/p pou dhmiourgoun difthoggous. Gia auto to logo
metavainoume se mia allh katastash, sthn opoia apofasizoume pws tha energhsoume*/
enum state stateStart(int c,enum state s,int M[255][3]){
    if(c==Mi) {
        s=SM;           /*An diavasw M paw sth katastash SM*/
    } 
    else if(c==Ni) {       /*An diavasw N paw sth katastash SN*/
        s=SN;
    } 
    else if(c==mi) {       /*An diavasw m paw sth katastash Sm*/
        s=Sm;
    } 
    else if(c==ni) {         /*An diavasw n paw sth katastash Sn*/
        s=Sn;
    }
    else {
        changeLetter(c,M);      /*an diavasw otidhpote allo tote odhgoumai sth sunarthsh changeletter*/
    }                       /*elegxw se poia apo tis prwtes 3 periptwseis vriskomai analoga me th timh tou c kai tupwnw to antistoixo*/
    return s;       /*se kathe sunarthsh epistrefw th katastash gia na enhmerwnw to state machine gia to new state*/
}
/*Gia na vriskomai se auth th katastash shmainei oti exw parei apo to input
to gramma N. 
1) Prepei na eksetasw th periptwsh pou akolouthei t h T giati prokuptei
to gramma D. An den akolouthei tipota apo ta duo tupwnw to N kai to gramma 
pou to akolouthei. 
2)An omws to gramma pou akolouthei einai to N h to n tote:
-An diavasw N tote menw sthn idia katastash gia na eleksw an o epomenos xarakthras pali
einai to t h to T.
-An diavasw n tote afou tupwsw to N(giati meta tha to xasw) metavainw sth katastash Sn 
gia na eleksw an o epomenos xarakthras einai to t h to T*/
enum state stateSN(int c, enum state s,int M[255][3]){
    if(c==Ni){    /*an diavasw N tupwnw N (aggliko) kai paramenw sthn idia katastash*/   
        putchar(En);      
    }
    else if(c==ni) {
        putchar(Ni);        /*an o epomenos xarakthras einai ni prepei na metavw sthn Sn gia na eleksw tis periptwseis*/
        s=Sn;
    }
    else if(c==Taf){          /*an pali diavasw T tote tupwnw D kai paw sth katastash T(NT->D)*/
        putchar(D);       
        s=ST;
    }
    else if(c==taf){            /*an diavasw t tote tupwnw pali D kai paw sth katastash t (Nt->D)*/
        putchar(D);
        s=St;
    }
    else {
        s=start;                /*an diavasw otidhpote allo paw sthn arxikh katastash,afou tupwsw to N kai to gramma pou diavasa*/
        putchar(En);
        changeLetter(c,M);
    }
    return s;
}

/*Gia na vriskomai se auth th katastash shmainei oti exw parei apo to input
to gramma n. 
1) Prepei na eksetasw th periptwsh pou akolouthei t h T giati prokuptei
to gramma d. An den akolouthei tipota apo ta duo tupwnw to n kai to gramma 
pou to akolouthei. 
2)An omws to gramma pou akolouthei einai to N h to n tote:
-An diavasw ni tote menw sthn idia katastash gia na eleksw an o epomenos xarakthras pali
einai to t h to T.
-An diavasw Ni tote afou tupwsw to n(giati meta tha to xasw) metavainw sth katastash SN
gia na eleksw an o epomenos xarakthras einai to t h to T*/
enum state stateSn(int c,enum state s,int M[255][3]){
    if(c==ni){             /*an diavasw n tote tupwnw to antistoixo aggliko*/
        putchar(en);      
    }
    else if(c==Ni) {
        putchar(ni);    /*an o epomenos xarakthras einai Ni prepei na metavw sthn SN gia na eleksw tis periptwseis*/
        s=SN;
    }
    else if(c==Taf){            /*an diavasw T tote tupwnw d kai paw sth katastash T (nT->d)*/
        putchar(d);       
        s=ST;
    }
    else if(c==taf){
        putchar(d);       /*an diavasw t tote tupwnw d kai paw sth katastash t (nt->d)*/
        s=St;
    }
    else {
        s=start;                /*an diavasw otidhpote allo paw sthn arxikh katastash,afou tupwsw to n kai to gramma pou diavasa*/
        putchar(en);
        changeLetter(c,M);
    }
    return s;
}

/*Gia na vriskomai se auth th katastash shmainei oti exei prohghthei to gramma n h to N.
auto pou prepei na elegksw einai an diavasw kainourio N/n. tote prepei na epistrepsw sth katastash SN/Sn
kai na elegksw ksana tis periptwseis. an de diavasw N h n tote teleiwsa
me ton difthoggo kai gurnaw sthn arxh ,afou tupwnw to antistoixo gramma pou diavasa*/
enum state stateST(int c,enum state s,int M[255][3]){
    if(c==Ni){     
        s=SN;           /*an diavasw N paw sthn SN*/
    }
    else if(c==ni) {
        s=Sn;                   /*an diavasw n paw sthn Sn*/
    }
    else {
        s=start;                /*an de diavasw tipota apo ta parapanw epistrefw sthn arxh afou tupwsw to c*/
        changeLetter(c,M);
    }
    return s;
}

/*Gia na vriskomai se auth th katastash shmainei oti exei prohghthei to gramma n h to N.
auto pou prepei na elegksw einai an diavasw kainourio N/n. tote prepei na epistrepsw sth katastash SN/Sn
kai na elegksw ksana tis periptwseis. an de diavasw N h n tote teleiwsa
me ton difthoggo kai gurnaw sthn arxh ,afou tupwnw to antistoixo gramma pou diavasa*/
enum state stateSt(int c, enum state s,int M[255][3]){
    if(c==Ni){         /*an diavasw N paw sthn SN*/
        s=SN;
    }
    else if(c==ni) {       /*an diavasw n paw sthn Sn*/
        s=Sn;
    }
    else {
        s=start;                /*an de diavasw tipota apo ta parapanw epistrefw sthn arxh afou tupwsw to c*/
        changeLetter(c,M);
    }
    return s;
}
/*Gia na vriskomai se auth th katastash shmainei oti exw parei apo to input
to gramma M. 
1) Prepei na eksetasw th periptwsh pou akolouthei p h P giati prokuptei
to gramma B. An den akolouthei tipota apo ta duo tupwnw to M kai to gramma 
pou to akolouthei. 
2)An omws to gramma pou akolouthei einai to M h to m tote:
-An diavasw M tote menw sthn idia katastash gia na eleksw an o epomenos xarakthras pali
einai to p h to P.
-An diavasw m tote afou tupwsw to M(giati meta tha to xasw) metavainw sth katastash Sm 
gia na eleksw an o epomenos xarakthras einai to p h to P*/
enum state stateSM(int c,enum state s,int M[255][3]){
    if(c==Mi){         
        putchar(Em);      /*an diavasw M tupwnw M(aggliko)*/
    }
    else if(c==mi) {
        putchar(Mi);        /*an o epomenos xarakthras einai mi prepei na metavw sthn Sm gia na eleksw tis periptwseis*/
        s=Sm;
    }
    else if(c==Pi){        
        putchar(B);       /*an pali diavasw P tote tupwnw B kai paw sth katastash P(MP->B)*/
        s=SP;
    }
    else if(c==pi){
        putchar(B);            /*an  diavasw p tote tupwnw B kai paw sth katastash p(Mp->B)*/
        s=Sp;
    }
    else {
        s=start;                /*an diavasw otidhpote allo paw sthn arxikh katastash,afou tupwsw to M kai to gramma pou diavasa*/
        putchar(Em);
        changeLetter(c,M);
    }
    return s;

}
/*Gia na vriskomai se auth th katastash shmainei oti exw parei apo to input
to gramma m. 
1) Prepei na eksetasw th periptwsh pou akolouthei p h P giati prokuptei
to gramma b. An den akolouthei tipota apo ta duo tupwnw to m kai to gramma 
pou to akolouthei. 
2)An omws to gramma pou akolouthei einai to M h to m tote:
-An diavasw m tote menw sthn idia katastash gia na eleksw an o epomenos xarakthras pali
einai to p h to P.
-An diavasw M tote afou tupwsw to m(giati meta tha to xasw) metavainw sth katastash SM 
gia na eleksw an o epomenos xarakthras einai to p h to P*/
enum state stateSm(int c,enum state s,int M[255][3]){
    if(c==mi){         
        putchar(em);      /*an diavasw m tupwnw m(aggliko)*/
    }
    else if(c==Mi) {
        putchar(mi);        /*an o epomenos xarakthras einai Mi prepei na metavw sthn SM gia na eleksw tis periptwseis*/
        s=SM;
    }
    else if(c==Pi){        
        putchar(b);       /*an pali diavasw P tote tupwnw b kai paw sth katastash P(mP->b)*/
        s=SP;
    }
    else if(c==pi){
        putchar(b);        /*an pali diavasw P tote tupwnw b kai paw sth katastash p(mp->b)*/
        s=Sp;
    }
    else {
        s=start;                /*an diavasw otidhpote allo paw sthn arxikh katastash,afou tupwsw to m kai to gramma pou diavasa*/
        putchar(em);           
        changeLetter(c,M);
    }
    return s;

}

/*Gia na vriskomai se auth th katastash shmainei oti exei prohghthei to gramma m h to M.
auto pou prepei na elegksw einai an diavasw kainourio M/m. tote prepei na epistrepsw sth katastash SM/Sm
kai na elegksw ksana tis periptwseis. an de diavasw M h m  tote teleiwsa
me ton difthoggo kai gurnaw sthn arxh ,afou tupwnw to antistoixo gramma pou diavasa*/
enum state stateSP(int c,enum state s,int M[255][3]){
    if(c==Mi){     
        s=SM;           /*an diavasw M paw sthn SM*/
    }
    else if(c==mi) {
        s=Sm;           /*an diavasw m paw sthn Sm*/
    }
    else {
        s=start;                /*an de diavasw tipota apo ta parapanw epistrefw sthn arxh afou tupwsw to c*/
        changeLetter(c,M);
    }
    return s;
}

/*Gia na vriskomai se auth th katastash shmainei oti exei prohghthei to gramma m h to M.
auto pou prepei na elegksw einai an diavasw kainourio M/m. tote prepei na epistrepsw sth katastash SM/Sm
kai na elegksw ksana tis periptwseis. an de diavasw M h m  tote teleiwsa
me ton difthoggo kai gurnaw sthn arxh ,afou tupwnw to antistoixo gramma pou diavasa*/
enum state stateSp(int c,enum state s,int M[255][3]){
    if(c==Mi){     
        s=SM;            /*an diavasw M paw sthn Sm*/
    }
    else if(c==mi) {
        s=Sm;                /*an diavasw m paw sthn Sm*/
    }   
    else {
        s=start;                /*an de diavasw tipota apo ta parapanw epistrefw sthn arxh afou tupwsw to c*/
        changeLetter(c,M);
    }
    return s;
}


