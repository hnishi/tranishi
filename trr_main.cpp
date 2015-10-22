#include"nlib.h"

using namespace std;


int main(int argc, char *argv[]){
   cout<<"Version info. tranishi v1.1.0 \n";
// ##################### ARGUMENT HANDLING ##########################
// argv[1]: input file
  if( argv[1]==NULL ){
    puts("No ARGUMEMTS");
    //puts("USAGE: ./a.out (input parameter file) ");
    puts("USAGE: ./a.out (trajectory) (pdb file) (optional: stride) (optional: selection)");
    puts("USAGE: selection: all, protein, heavy, mainchain, ca  ");
    return 1;
  }
  //cout<<"Your input files: "<<argv[1]<<endl;

// INPUT_PARAMETERS
//Inp_nishi inp1( argv[1] );

  int stride = 1;
  string selectatom = "all";

  string codname = argv[1];
  string pdbname = argv[2];
  if( argv[3] )stride = atoi(argv[3]);
  if( argv[4] )selectatom = argv[4];

// Tranishi
	cout<<"now loading cod file \n";
	tra_nishi tra1( codname.c_str(), pdbname.c_str(), selectatom.c_str() );
	cout<<"TOTAL STEP = "<<tra1.total_step<<endl;
	cout<<"STRIDE = "<<stride<<endl;
	//tra1.pdb1->write_pdb("xxx.pdb");
	//tra1.write_step("md.pdb", 0);
	//tra1.disp_line(tra1.total_step-1);
	//tra1.write_cod("zzz.pdb",1);
	//tra1.fix_cod_npt();
	tra1.fix_cod(40.2796,40.2796,40.2796);  // for md_pra.cod and pra.pdb

	if(tra1.total_step/stride>500){
		puts("Number of frames of your input is more than 500.");
		puts("You can set a third argument as a stride number when the output file is too large to show movies with some viewer.");
		puts("!!! Do you change the stride? put 'y' or 'n'");
		string yn;
		cin >> yn;
		if( yn == "y" ){
			puts("How long is the stride? enter");
			cin >> stride;
			puts("OK!!!, please wait, writing trajectory in ASCII.");
		}
	}

	cout<<"now writing trajectory in ASCII \n";
	tra1.write_cod( "out_traj.pdb", stride);
	//fix_cod("out_traj.pdb",stride,float fxcell,float fycell,float fzcell);
	cout<<"output out_traj.pdb"<<endl;
	cout<<"finished!!!"<<endl;
// END
	cout<<"\nit took "<<(float)clock()/CLOCKS_PER_SEC<<" sec of CPU to execute this program"<<endl;
	return 0;
}
