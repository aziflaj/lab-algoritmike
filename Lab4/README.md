# Lab 4 - Pemet binare te kerkimit (Binary Search Tree - ABR)

Ne kete pune do te fokusohemi tek ndertimi i pemeve binare te kerkimit. Funksionet
qe duhen ndertuar per kete pjese jane:

 1. Shkruani strukturen `node` te nje ABR.
 2. Shkruani funksionin iterative `node *insertNode(int n, node *root)` qe ben te mundur futjen e vleres n ne nje peme me rrenje root. Cili eshte kompleksiteti i ketij funksioni?
 3. Shkruani funksionin `node* insertNode_rec(int n, node *root)` qe ben te mundur futjen e vleres n ne nje peme me rrenje root ne menyre rekursive. Percaktoni per te dy rastet kohen qe duhet per te ekzekutuar funksionin rekursiv dhe ate iterativ duke perdorur te njeten instance per testim. Shenim: per llogaritjen e kohes mund te perdorni kodin e meposhtem.

```c
clock_t start, end;
double elapsed;
start = clock(); /* Fillimi i matjes */
/* ... */ 
/* kodi */
end = clock(); /* ndalimi i matjes */
elapsed = ((double)end - start) / CLOCKS_PER_SEC; /* Konvertimi ne seconda */
```

Funksioni `clock()` ndodhet ne librarine e `time.h`.


Shembull: Supozojme qe eshte dhene pema A. Pas futjes se numrit 45, perftohet pema B.

![Shembull]()

4. Shkruani funksionin `node *research(int n, node *root)` qe gjen elementin me vlere n ne pemen ne pemen me rrenje root. Cili eshte kompleksiteti i ketij funksioni?
5. Shkruani funksionin `int* length(node *root)` qe gjen gjatesine e pemes. Psh gjatesia e pemeve `A` dhe `B` eshte 3.
6. Shkruani funksionin `void display_Decreasing(node *root)` qe afishon elementet e pemes ne rendin zbrites.
7. Shkruani funksionin `void delete(int n, node *root)` qe fshin elementin me vlere `n` ne pemen ne pemen me rrenje root. Ne rastin kur ky element nuk ekziston, atehere ne akran duhet te afishohet pikerisht ky fakt.

