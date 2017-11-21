TChain* chain(){
	TChain* ch = new TChain();
	ch->Add("./output/Oct_04_14_02/tree*.root/tree");
	return ch;
}
