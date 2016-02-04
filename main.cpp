#include"nlib.h"

using namespace std;


int main(int argc, char *argv[]){
   cout<<"Version info. tranishi v1.2.0 \n";
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
	//tra_nishi tra1(inp1.read("CODNAME").c_str(),inp1.read("REFPDBNAME").c_str(),inp1.read("SELECTATOM").c_str());
	//tra_nishi tra1("../samp/md_pra.cod","../samp/pra.pdb","protein");
	tra_nishi tra1( codname.c_str(), pdbname.c_str(), selectatom.c_str() );
	//tra_nishi tra1("../samp/for_rmsd/traj/md_small.crd","../samp/for_rmsd/traj/crystal_1st.pdb");
	//tra_nishi tra1("samp/md_npt_10.cod","samp/10_min3.pdb",10);
	//tra_nishi tra1("samp/md_npt_10.cod","samp/md0.out.pdb",1);
	cout<<"TOTAL STEP = "<<tra1.total_step<<endl;
	cout<<"STRIDE = "<<stride<<endl;
	//for(unsigned int i=0;i<tra1.total_step;i++){
	//for(unsigned int i=tra1.total_step-1;i<tra1.total_step;i++){
		//cout<<tra1.length_x[i]<<endl;;
		//tra1.disp_line(i);
	//}
	//tra1.pdb1->write_pdb("xxx.pdb");
	//tra1.write_step("OUTPDBNAME",tra1.total_step -1);
	//tra1.write_step("md.pdb", 0);
	//tra1.disp_line(tra1.total_step-1);
	//tra1.write_cod("zzz.pdb",1);
	//tra1.write_cod("zzz_100koma.pdb",1);
	//tra1.write_step("10_npt_43000.pdb",42);
	//tra1.fix_cod_npt();
	//tra1.fix_cod(77.63074,80.07944,158.1261);  // for md_pra.cod and pra.pdb
	//int stride = atoi( inp1.read("STRIDE").c_str() );
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

	//char s1[sizeof(argv)] = "out_";
	//strcat();
	cout<<"now writing trajectory in ASCII \n";
	//tra1.write_cod(inp1.read("OUTCODNAME").c_str(),stride);
	tra1.write_cod( "out_traj.pdb", stride);
	//fix_cod("out_traj.pdb",stride,float fxcell,float fycell,float fzcell);
	cout<<"output out_traj.pdb"<<endl;
	cout<<"finished!!!"<<endl;
// END
	cout<<"\nit took "<<(float)clock()/CLOCKS_PER_SEC<<" sec of CPU to execute this program"<<endl;
	return 0;
}
