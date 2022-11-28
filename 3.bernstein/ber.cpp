#include<iostream>
using namespace std;

int main(){
    int n;

    freopen("input.txt","r",stdin);

    cout<<"Number of process: ";
    cin>>n;
    cout<<n<<endl;

    string instruction;
    string  input_set[n][10];
    string output_set[n];
    int input_len[n];
    string dependency[15];

    for(int i=0;i<n;i++){
        cout<<"program order: ";
        cin>>instruction;
        cout<<instruction<<endl;

        // separate input set
        int index = 0;
        for (int j=5;j<instruction.size();j++){
            if((instruction[j]>='a'&& instruction[j] <= 'z') || (instruction[j] >= 'A' && instruction[j] <= 'Z')){
                input_set[i][index] = instruction[j];
                index++;
            }
        }
        input_len[i]=index;

        // separate output set
        output_set[i]=instruction[3];
    }

    // // print inputs and outputs
    // for(int i=0;i<n;i++){
    //     cout<<"inputs: ";
    //     for(int j=0;j<=input_len[i];j++){
    //         cout<<input_set[i][j];
    //     }
    //     cout<<" and output: "<<output_set[i]<<endl;
    // }

    // check bernstein condition

    int iteration = 0;
    for(int i = 0;i<n;i++){
        for (int j = i+1;j<n;j++){
            bool condition = true;
            
            // check output dependency
            if(output_set[i]==output_set[j]){
                condition = false;

                dependency[iteration] = "P"+to_string(i+1)+ " Output dependent on P"+to_string(j+1);
                iteration++;
            }

            // check anti dependency
            for(int k = 0;k<input_len[i]; k++){
                if(input_set[i][k] == output_set[j]){
                    condition = false;

                    dependency[iteration] = "P"+to_string(i+1) + " Anti dependent on " + "P" + to_string(j+1);
                    iteration++;
                }
            }

            // check flow dependency
            for(int k=0; k<input_len[j]; k++) {
                // O1 == I2
                if(output_set[i] == input_set[j][k]) {
                    condition = false;

                    dependency[iteration] = "P"+to_string(i+1) + " Flow dependent on " + "P" + to_string(j+1);
                    iteration++;
                }
            }

            if(condition){
                cout << "P" << i+1 << "||" << "P" << j+1 << endl;
            }
        }
    }
    cout<<endl<<"Dependency graph"<<endl;
    for(int i = 0;i<iteration;i++)
    {
        cout<<dependency[i]<<endl;
    }
    return 0;
}