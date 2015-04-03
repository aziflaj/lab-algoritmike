#LAB #1

### 1. Pershkrimi i problemit
Qellimi i ketij laboratori eshte perdorimi i strukturave dhe FILE per leximin e te dhenave. Konkretisht, programi do te shkruhet per te zgjidhur nje problem nga fusha e biologjise.
Ne fazen e pare, te dhenat e problemit do te simulohen duke perdorur modelin matematik te FitzHugh-Nagumo (shiko [seksionin A](#a-ekuacionet-e-fitzhugh---nagumo)). Keto te dhena do te krahasohen me te dhenat e matura eksperimentalisht te cilat jane ruajtur ne nje skedar te quajtuar `cell.txt`. Me tutje, do te gjendet gabimi midis te dhenave te lexuara nga skedari dhe
te dhenave te llogaritura nga modeli teorik.
Ne fazen e dyte, i njejti problem do te zgjidhet por duke perdorur alokacioni dinamik. Studentit i kerkohet qe te implementoje hap pas hapi te gjitha funksionet e meposhtme.

### 2. Pjesa e pare, tabelat statike
Te dhenat do te ruhen ne strukturen "trace" e detajuar si me poshte:
```C
typedef struct{
	char comment[40];
	int nbpts;
	float time[4096];
	float value[4096];
} trace;
```

Ne kete strukture, `comment` i referohet Emrit te Eksperimentit te kryer, tabela `time` ruan vlerat e kohes kur jane matur/llogaritur te dhenat dhe `value` ruan vlerat e matura ne kohen perkatese. Do te pranojme qe gjithsej mund te masim 4096 vlera.

 - Shkruani funksionin `simutrace(int tmax, float dt, float params[], trace uneTrace)`. Ky funksion duhet te mbush strukturen `uneTrace`. Per kete faze simulimi, do te zgjedhim `tmax = 1000ms` dhe `dt = 0.5ms`, per t’i pershtatur me te dhenat e eksperimentit. Per me tutje do te perdorim ekuacionet e modelit ne seksionin A.
 - Shkruani funksionin printT race(trace uneTrace) i cili do te afishoj ne ekran permajtjen e struktures ne menyren e meposhtme:
```
CommentsOfTrace
t=0.0 v=0.0000
t=0.5 v=0.0000
t=1.0 v=0.0001
t=1.5 v=0.0003
...
```
 - Shkruani funksionin `saveTraceBin(char  Filetrace, trace uneTrace)` qe do te ruante te dhenat e uneTrace ne nje file, ne menyre qe te dhenat te mund te perdoren me vone.

#### 2.1 Leximi i skedarit te eksperimentit
Ne kete pjese duhet te lexojme rezultatet e eksperimentit te regjistruar ne file `cell.txt`.

 - Shkruani funksionin `readTrace(char  fileName, trace  uneTrace)` qe do te lexonte permajtjen e file, emri i te cilit kalohet si argument i funksionit, dhe rimbush strukturen uneTrace me te dhenat e lexuara.
 - Afishoni te dhenat e lexuara.

#### 2.2 Perfundimet e fazes se pare

 - Shkruani funksionin `errorTrace(trace uneTrace1, trace uneTrace2)` qe do te kthente gabimin midis te dhenave te matura dhe atyre te llogaritura duke u bazuar ne formulen ne [seksion B](#b-error-computation).
 - Llogarisni kete gabim per dy tabelat me parametra: `Pa` dhe `Pb` dhe nxirrni perfundimin se cila prej tyre eshte me e favorshme.


### 3. Pjesa e dyte, alokacioni dinamik
Ne pjesen e pare, kemi supozuar qe mund te perdorim maksimalisht 4096 vlera. Ne kete faze do te supozojme qe numri i vlerave do te jete nje variable i cili lexohet nga skedari `cell.txt`. Si rrjedhim struktura e re qe po perdoret eshte:

```C
typedef struct{
	char comment[40];
	int nbpts;
	float *time;
	float *value;
} trace;
```

Shkruani funksionet e pjeses se pare duke perdorur strukturen e re.

### A. Ekuacionet e FitzHugh - Nagumo
![dV/dt](http://www.sciweavers.org/upload/Tex2Img_1427970833/render.png)

![dw/dt](http://www.sciweavers.org/upload/Tex2Img_1427970754/render.png)

Parametrat ![epsilon](http://www.sciweavers.org/upload/Tex2Img_1427970900/render.png),![delta](http://www.sciweavers.org/upload/Tex2Img_1427970938/render.png), ![alpha](http://www.sciweavers.org/upload/Tex2Img_1427970951/render.png) jane vleresuar dhe rezultatet jane dhene ne dy tabela te quajtuara
Pa dhe Pb. 
![Pa](http://www.sciweavers.org/upload/Tex2Img_1427970857/render.png)
![Pb](http://www.sciweavers.org/upload/Tex2Img_1427970881/render.png)

**Algorithm1: Algoritmi i Eulerit per zgjidhjen e ekuacioneve diferencial**
```
Data: tmax, dt, e, d, a;
Initialization: Time[], Trace[];
int i=0;
float v=0, w=0, dv=0, dw=0, t=0;
while t<tmax do
	dv = (a-v)(v-1)v-w;
	dw = e(0.5v-w-d);
	v += dv * dt;
	w += dw * dt;
	Time[i] = t;
	Trace[i] = v;
	i++;
	t += dt;
end
```

### B. Error Computation
Per te llogaritur gabimin midis vleres se matur ![x](http://www.sciweavers.org/upload/Tex2Img_1428071562/render.png) dhe vleres se simuluar ![x'](http://www.sciweavers.org/upload/Tex2Img_1428071582/render.png) do perdorim ekuacionin e meposhtem:
![error trace](http://www.sciweavers.org/upload/Tex2Img_1427970967/render.png)
