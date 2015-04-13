# LAB #2

## 1. Hyrje
Ne duam te stokojme dhe te manipulojme tekste me madhesi te pepercaktuar ne memorie. Atehere ne do te reprezantojme nje text me nje liste zinxhir te dyfishte:

![bidirectional-list](https://raw.githubusercontent.com/aziflaj/lab-algoritmike/master/Lab2/bi-list.png)

## 2. Struktura e te dhenave
 - Deklaroni konstanten `N`.
 - Percaktoni strukturen `node` e cila perfaqeson nje element te listes. Cdo nyje e listes do te permbaje:
	 - Nje tabele karakteresh te quajtur `data` me madhesi `N`.
	 - Nje numer te plote te quajtur `size` qe percakton numrin e elementeve te vendusur ne tabele
	 - Nje pointer `next` qe pointon drejt nyjes pasardhese.
	 - Nje pointer `prev` qe pointon drejt nyjes paraardhese.


Me `N = 4`, nje shembull i textit _"Hello world!"_ jepet nga skema e mesiperme.

- Percaktoni nje strukture `text` per te ruajtur textin. Struktura permban:
	- Nje ponter te quajtur `head` per te identifikuar nyjen e pare. 
	- Nje ponter te quajtur `tail` per te identifikuar nyjen e fundit.
	- Nje numer te plote `count` per te identifikuar numrin e elementeve ne text.
	- Nje numer te plote `size` per te identifikuar numrin e karaktereve te text.

- Shkruani nje strukture `iter` per te ruajtur nje kursor ne nje text (pozicioni relativ) e cila permban:
	 - Nje pointer `ptr` per te identifikuar nyjen e `text`-it ku eshte kursori.
	 - Nje numer te plote `icase` per te identifikuar elementin perkates te tabeles.

Vlera `NULL` e `ptr` tregon qe kursori eshte vendosur perpara elementit te pare. 


## 3. Funksionet baze
Pas deklarimeve, ne kete pjese ju kerkohet te zhvilloni funksionet me prototipe si me poshte:

- `node* create_node()`
i cili krijon dhe kthen nje nyje bosh.

- `text* create_text()`
i cili krijon dhe kthen nje text bosh.

- `void free_text(text* t)`
i cili cliron memorien nga `text* t` se bashku me nyjet perkatese qe e perbejne.

- `iter* create_iter_at_begin(text* t)`
qe krijon nje kursor dhe e pozicionon tek karakteri i pare i textit.

- `void free_iter(iter* pos)`
qe cliron kursorin `pos`.

_Funksionet e levizjes se kursorit duhet te garantojne qe kursori qendron gjithmon midis elementit te pare dhe te fundit._

- `void append_text(text* t, char* s)`
qe shton nje zinxhir karakteresh `s` ne fund te textit `t`. Ky funksion duhet te shrytezoje maximumin e vendeve bosh qe ndodhen ne nyjen e fundit te `text`-it `t`.

- `void push_text(text* t, char* s)`
qe shton nje zinxhir karakterash s ne fillim te textit `t`.

- `void show_text(text * t, iter * pos)`
qe afishon `text`-in `t` me nje yll (`*`) ne pozicion ku ndodhet kursori `pos`. Nese `pos->ptr` eshte `NULL`, ylli afishohet perpara karakterit te pare.
