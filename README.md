# OOP_Homework
OOP Course Homework

Să se construiască clasa Apartament cu următoarele atribute:

• an construcție bloc (întreg constant)

• adresa (șir de caractere) – la alegere se poate construi ca un pointer dinamic la zonă de
memorie dinamică de tip char sau pointer dinamic la zonă de memorie constantă de tip char
sau se poate utiliza tipul string

• decomandat (boolean)

• preț (float) – prețul de vânzare în euro (să nu fie mai mic de 30.000 de euro și să nu fie mai
mare de 200.000 de euro)

• număr camere (întreg) – numărul de camere al apartamentului (trebuie să fie cel puțin o
cameră, dar nu mai mult de 4)

• suprafețe camere (vector alocat dinamic cu elemente de tip float) – valorile suprafețelor
fiecărei camere

• atribut la alegere static

1. Să se realizeze constructorul implicit, doi constructori cu parametri și destructorul. În cei
doi constructori cu parametri se vor face validări. Unul dintre constructorii cu parametri va
conține parametri pentru toate atributele, iar celălalt constructor cu parametri va conține
parametrii pentru o parte dintre atributele clasei. Nu se va lăsa niciun atribut neinițializat.

2. Să se realizeze metode de acces pentru 3 membrii ai clasei. Unul dintre membrii clasei
pentru care se fac metodele de acces să fie un atribut dinamic. Să se facă validări ale
parametrilor primiți în setteri.

3. Să se realizeze constructorul de copiere pentru clasa Apartament.

4. Să se supraîncarce operatorul = fără a genera memory leaks.

5. Supraîncărcarea operatorilor << și >> pentru scrierea și citirea obiectelor de tip Apartament
din consolă.

6. Să se supraîncarce operatorul += pentru a se adăuga o nouă cameră. Suprafața camerei este
introdusă ca parametru. Mare atenție aici să vedeți câte camere aveți deja!

7. Supraîncărcarea operatorului de indexare [] pentru accesarea elementelor din vector, cu
verificare la indexul introdus. Supraîncărcarea operatorului [] permite doar vizualizarea
elementului din vector, nu și modificarea acestuia.

8. Supraîncărcarea la alegere a unuia dintre operatorii >, <, >=, <= sau == pentru a se compara
prețurile între două obiecte de tip Apartament.

9. Realizarea unei metode statice care va primi un vector de apartamente și numărul de
apartamente și care să returneze media prețurilor apartamentelor.

10. Realizarea a două metode membre clasei numite calculSuprafataTotala() și
calculPretPeMetruPatrat(). Metoda calculSuprafataTotala() returnează suprafața totală a
apartamentului, iar metoda calculPretPeMetruPatrat() returnează prețul în euro pe metru
pătrat al apartamentului.
Toate implementările din cerințele de mai sus vor fi testate în main. Atributele clasei vor fi
implementate în zona privată a clasei.
