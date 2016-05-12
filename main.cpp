#include"nlib.h"

using namespace std;

int main(int argc, char *argv[]){
   cout<<"Version info. tranishi v1.3.6 \n";
// ##################### ARGUMENT HANDLING ##########################
  if( argv[1]==NULL ){
    puts("No ARGUMEMTS");
    puts("USAGE: ./a.out (trajectory) (pdb file) (optional: FRAME INTERVAL) (optional: ATOM SELECTION)");
    puts("USAGE: selection: all, protein, heavy, mainchain, ca  ");
    return 1;
  }
  
// INPUT_PARAMETERS

  int stride = 1;
  string selectatom = "all";

  string codname = argv[1];
  string pdbname = argv[2];

  string argu3; 
  if( argv[3] ){
    argu3 = argv[3];
    stride = atoi(argu3.c_str());
    if(stride==0&&(argu3=="all"||argu3=="protein"||argu3=="heavy"
          ||argu3=="mainchain"||argu3=="ca")){
    selectatom = argu3;
    stride = 1;
  }}

  string argu4;
  if( argv[4] ){argu4= argv[4];
  if(atoi(argu4.c_str())){stride=atoi(argu4.c_str());}
  else if(argu4=="all"||argu4=="protein"||argu4=="heavy"
          ||argu4=="mainchain"||argu4=="ca"){
    selectatom = argu4;
  }}

// Tranishi
  cout<<"### your input information ###\n";
  cout<<"ATOM SELECTION = "<<selectatom<<endl;
  cout<<"FRAME INTERVAL = "<<stride<<endl;
  cout<<"### now loading cod file ###\n";
  tra_nishi tra1( codname.c_str(), pdbname.c_str(),stride, selectatom.c_str() );
  cout<<"TOTAL FRAME = "<<tra1.total_step<<endl;
  //tra1.pdb1->write_pdb("xxx.pdb");
  //tra1.write_step("md.pdb", 0);
  //tra1.write_cod("zzz.pdb",1);
  //tra1.fix_cod_npt();
  //tra1.fix_cod(77.63074,80.07944,158.1261);  // for md_pra.cod and pra.pdb
  if(tra1.total_step/stride>500 && selectatom == "all"){
    puts("WARNING: Number of frames of your input is more than 500.");
    puts("You can set a third argument as a stride number when the output file is too large to show movies with some viewer.");
  }
 /*puts("!!! Do you change the stride? put 'y' or 'n'");
		string yn;
		cin >> yn;
		if( yn == "y" ){
			puts("How long is the stride? enter");
			cin >> stride;
			puts("OK!!!, please wait, writing trajectory in ASCII.");
		}
	}*/

	cout<<"### now writing trajectory in ASCII ###\n";
	tra1.write_cod( "out_traj.pdb", 1);
	cout<<"output out_traj.pdb"<<endl;
// END
	cout<<"\nfinished!!!"<<endl;
	cout<<"it took "<<(float)clock()/CLOCKS_PER_SEC<<" sec of CPU to execute this program"<<endl;
	return 0;
}
