#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

int convert(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }
  return dec;
}

string sumador_binario(string b1, string b2, string Resultado1){
  int tam, acarreo, r, i;
  tam = b1.size();
  Resultado1 = "";
  acarreo = 0;
  for(i=(tam-1); i>-1; i--)
    {
      r = acarreo;
      if(b1[i] == '1')
         r = r+1;
      else
         r = r+0;
      if(b2[i] == '1')
         r = r+1;
      else
         r = r+0;
      if(r%2==1)
         Resultado1 = '1' + Resultado1;
      else
         Resultado1 = '0' + Resultado1;
      if(r<2)
         acarreo = 0;
      else
         acarreo = 1;
    }
    if(acarreo!=0)
      Resultado1 = '1' + Resultado1;

  return Resultado1;
}


int main() {
  float x, y;
  string Resultado1, Resultado2, Resultado3, Resultado4;
  unsigned int* a;
  unsigned int* b;
  a = (unsigned int*) (&x);
  b = (unsigned int*) (&y);
  cout << "INGRESE LA PRIMERA VARIABLE DE TIPO FLOAT" << endl;
  cin >> x;
  cout << "INGRESE LA SEGUNDA VARIABLE DE TIPO FLOAT" << endl;
  cin >> y;
  cout << x << " EN BINARIO " << bitset<32>(*a)  << endl;
  cout << "SIGNO          " << bitset<1>(*a >> 31) << endl;
  cout << "EXPONENTE      " << bitset<8>(*a >> 23) << endl;
  cout << "SIGNIFICANDO   " << bitset<23>(*a) << endl;
  cout << y << " EN BINARIO " << bitset<32>(*b)  << endl;
  cout << "SIGNO          " << bitset<1>(*b >> 31) << endl;
  cout << "EXPONENTE      " << bitset<8>(*b >> 23) << endl;
  cout << "SIGNIFICANDO   " << bitset<23>(*b) << endl;
  if (x == 0 || y == 0){
    cout << "EL RESULTADO DE LA MULTIPLICACIÓN ES 0" << endl;
  } else {
    string b1 = bitset<8>(*a >> 23).to_string();
    string b2 = bitset<8>(*b >> 23).to_string();
    Resultado1 = sumador_binario(b1, b2, Resultado1);
    int r = convert(stoi(Resultado1)) - 128;
    cout << bitset<8>(r)<< endl;
    string b3 = (bitset<23>(*a).to_string());
    string b4 = (bitset<23>(*b).to_string());
    for (int i = 0; i < 23; i++){
      if (b4[i] != '0'){
        Resultado2 = sumador_binario(b3, b4, Resultado2);
        Resultado3 = sumador_binario(Resultado2, Resultado3, Resultado3);
      }
      b3.append("0");
    }
    string significante;
    char aux;
    int redondeo = 1;
    int signo;
    for (int i = 0; i < 23; i++){
      aux = Resultado3[i];
      significante.push_back(aux);
    }
    if (Resultado3[23] == 1){
      int tmp = 22;
      while (redondeo != 0){
        if (significante[tmp] == 1){
          significante[tmp] = '0';
          redondeo = 1;
        } else 
          significante[tmp] = '1';
        tmp--;
      }
    }
    if (((bitset<1>(*a >> 31)) == '0' && (bitset<1>(*b >> 31)) == '0') || ((bitset<1>(*a >> 31)) == '1' && (bitset<1>(*b >> 31)) == '1'))
      signo = 0;
    else
      signo = 1;
    cout << "EL RESULTADO DE LA MULTIPLICACIÓN ES: " << signo << Resultado1 << significante << endl;
  }
}
