
int M[100][100];

int columnWithMaxZeros(int);


int columnWithMaxZeros(int N){
    
    // Your code here
    int c[N];//intialize the array
    for (int i=0;i<N;i++){
        
        c[i]=0;
    }
    
    for (int i=0;i<N;i++){
        
        for(int j=0;j<N;j++){
            if (M[i][j]==0){
                
                c[j] = c[j] + 1;
              
            }
        }
        
    }
    
    int max=0;
    
    for(int i=1;i<N;i++){
        if(c[i]>c[max]){
            max=i;
        }
        
    }
    return max;
    
}

// Driver code to test columnWithMaxZeros function
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    
	    // Taking elements input into the matrix
	    for(int i = 0;i<N;i++){
	        for(int j = 0;j<N;j++){
	            cin >> M[i][j];
	        }
	    }
	    
	    cout << columnWithMaxZeros(N) << endl;
	}
	
	return 0;
}