//Santiago Torres Alvarez
#include <vector>
#include <iostream>

using namespace std;

//p = vect de probabilidades indexado desde 0...(n-1)
//pacum = vector de prob acumuladas indexada desde 0..n
//Complejidad: O(n^3)
float BSTOp(vector<float> &p, vector<float> &pacum){
  int n = p.size()
  float A[n+1] [n+1];
  for(int i=1; i<= n; i++){
    A[i][i-1] = 0;
    A[i][i] = p[i-1];
  }
  for(int diag =1; diag <n; diag++){
    for(int i=1; i<n-diag;i++){
      int j=i+diag;
      float min  = A[i][i-1] + A[i+1][j];
      for(int k = i+1; k<= j; k++){
        if(A[i][k-1]+A[k+1][j] < min){
          min = A[i][k-1]+A[k+1][j];
        }
      }
      // pacum[j] - pacum[i-1] me dara la suma de las prob de los 
      //nodos involucrados
      A[i][j] = min + pacum[j] - pacum[i-1];
    }
  }
  return A[1][n];
} 


int main() {
  int n; //cant de nodos
  float dato;
  cin >> n;
  //p  = vector con las probabilidades 
  // pacum = vect con las probs acumuladas
  vector<float> p, pacum; 
  pacum.push_back(0);
  for(int i=0; i<n; i++){
    cin >>dato;
    p.push_back(dato);
    pacum.push_back(pacum[i] +dato);

  }
  cout << BSTOp (p, pacum) << endl;

}


// 5
// .2
// .15
// .2
// .3
// .15