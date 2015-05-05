# Lab 3 - Listat zinxhir te dyfishta dhe editimi i textit, vazhdim

![bidirectional-list](https://raw.githubusercontent.com/aziflaj/lab-algoritmike/master/Lab3/bi-list.png)

***Laboratori i trete do te jete vazhdim i laboratorit te dyte , i bazuar ne manipulimet e listave te dyfishta. Ketu do t’ju kerkohet te zhvilloni te tjera funksione qe do sherbejne per editimin e metejshem te textit.***

## Funksionet
Ne vijim te funksioneve te ndertuara ne laboratorin e dyte, ketu do ndertohen funksionet e meposhtme:

 - `void move_forward_iter(iter * pos, int n)`
ky funksion ben te mundur zhvendosjen e kursorit `pos` me `n` karaktere ne te djathte. Ne rast se kursori nuk mund te zhvendoset me `n` karaktere, atehere ai duhet te pozicionohettek karakteri i fundit.

 - `void move_backward_iter(iter * pos, int n)`
ky funksion bent e mundur zhvendosjen e kursorit `pos` me `n` karaktere ne te majte. Ne rast se kursori nuk mund te zhvendoset me `n` karaktere, atehere ai duhet te pozicionohettek karakteri i pare.

 - `float eval_text(text * t)`
i cili llogarit efikasitetin e perdorimit te memories. Funksioni duhet te kthej nje vlere midis 0% dhe 100%, e cila llogaritet duke pasur parasysh fushat `size`, `count`, `t` si dhe `N`. Per shembull: Efikasiteti ne rastin e figures eshte: 12/13=92.30%. Ne rastin kur teksti ka vetem nje nyje, atehere efikasiteti do te konsiderohet 100%.

 - `void push_text(text * t, char * s)`
i cili shton nje zinxhir karakteresh `s` ne fillim te textit `t`.

 - `void insert_text(text * t, iter * pos, char * s)`
i cili shton zinxhirin e karaktereve `s` aty ku eshte kursori `pos`. Per me teper, duhet qe kursori te vendoset tashme ne karakterin e fundit te `s`.

 - `void show_text(text * t, iter * pos)`
i cili afishon textin `t` me nje yll [`*`] pas karakterit ku pointon `pos` ([`*`] perfaqson pozicionin e kursorit). Nese `pos->ptr` eshte `NULL`, ylli vendoset perpara karakterit te pare.

 - `void delete_text(text * t, iter * pos, int n)`
i cili fshin `n` karaktere perpara `pos` (karakteri qe pointohet nga `pos` eshte i perfshire). Nderkohe `pos` duhet te update-ohet per te treguar karakterin e fundit qe nukeshte fshire. Nese nuk ka karaktere te tjere, duhet qe `pos->ptr = NULL`.

 - `void shift_text(text * t, iter * pos)`
i cili zhvendos karakteret brenda textit `t` me qellim qe te maksimizohet efikasiteti i memories (`eval_text` duhet te ktheje 100%).

## Demo
Ne file tuaj duhet te shfaqet menuja e meposhtme:

```bash
1. Lexoni nje file.txt.
2. Ruani textin.
3. Afishoni textin.
4. Zhvendosni kursorin n karaktere ne te djathte.
5. Zhvendosni kursorin n karaktere ne te majte.
6. Fshini n karaktere duke filluar nga karakteri i pointuar nga kursori.
7. Fusni nje zinxhir karakteresh duke filluar nga karakteri i pointuar nga kursori.
8. E zhendosim karakteret e tekstit ne menyre qe efikasiteti te jete 100%.
9. Dalim nga cikli.
```
