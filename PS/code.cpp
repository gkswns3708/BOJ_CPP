#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long int
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k; cin >> n >> k;
	string ans;
	vector<string> vec{ "a","aabb","aaccbbabc","aaddccbbacabdbcd","aaeeddccbbacebdadbecabcde","aaffeeddccbbaceadaecabdfbebfdbcfcdef","aaggffeeddccbbacegbdfadgcfbeaebfcgdafdbgecabcdefg","aahhggffeeddccbbacegadgbehcfaeafchebgdagecabdfhbfbhfdbcgcdhdefgh","aaiihhggffeeddccbbacegibdfhadgaeidhcgbfafbgchdieagdahfdbigecabehbhebcficifcdefghi","aajjiihhggffeeddccbbacegiadgjcfibehaeicgafagcieahebifcjgdaigecabdfhjbfjdhbgbhdjfbjhfdbchcdidejefghij","aakkjjiihhggffeeddccbbacegikbdfhjadgjbehkcfiaeibfjcgkdhafkejdichbgagbhcidjekfahdkgcjfbieaifckhebjgdajhfdbkigecabcdefghijk","aallkkjjiihhggffeeddccbbacegikadgjaeiafkdibglejchagahcjelgbidkfaieajgdakigecabdfhjlbehkbfjbhbjfbkhebljhfdbcfilcgkcickgclifcdhldjdlhdekeflfghijkl","aammllkkjjiihhggffeeddccbbacegikmbdfhjladgjmcfilbehkaeimdhlcgkbfjafkchmejbgldiagmflekdjcibhahbicjdkelfmgaidlgbjemhckfajfbkgclhdmieakheblifcmjgdaljhfdbmkigecabcdefghijklm","aannmmllkkjjiihhggffeeddccbbacegikmadgjmbehkncfilaeimcgkafkbglchmdinejagmekciahaickemgajenidmhclgbkfakgcmiealifcnkhebmjgdamkigecabdfhjlnbfjndhlbhnfldjbibjdlfnhblhdnjfbnljhfdbcjcdkdelefmfgnghijklmn","aaoonnmmllkkjjiihhggffeeddccbbacegikmobdfhjlnadgjmaeimbfjncgkodhlafkagmdjahognfmeldkcjbiaibjckdlemfngohajdmgakfalhdokgcnjfbmieamjgdanljhfdbomkigecabehknbglbhnekbkenhblgbnkhebcfilochmcioflclfoicmhcolifcdindnidejoeojefghijklmno","aappoonnmmllkkjjiihhggffeeddccbbacegikmoadgjmpcfilobehknaeimafkpejodinchmbglagmcioekahofmdkbipgnelcjaiajclengpibkdmfohakeoicmgalgbmhcnidojepkfamieankhebolifcpmjgdaomkigecabdfhjlnpbfjnbhndjpflbjblfpjdnhbnjfbpnljhfdbcgkockcokgcdhlpdldplhdemefnfgoghphijklmnop","aaqqppoonnmmllkkjjiihhggffeeddccbbacegikmoqbdfhjlnpadgjmpbehknqcfiloaeimqdhlpcgkobfjnafkpdinbglqejochmagmbhnciodjpekqflahoelbipfmcjqgndkaiqhpgofnemdlckbjajbkcldmenfogphqiakdngqjcmfpibleohalfqkepjdoicnhbmgamhcojeqlgbnidpkfanjfbokgcplhdqmieaolifcqnkhebpmjgdapnljhfdbqomkigecabcdefghijklmnopq","aarrqqppoonnmmllkkjjiihhggffeeddccbbacegikmoqadgjmpaeimqcgkoafkpchmrejobglqdinagmahodkrgncjqfmbipelaiqgoemckajakcmeogqialepibmfqjcngrkdohamganidqlgbojermhcpkfaokgcqmieapmjgdaqomkigecabdfhjlnprbehknqbfjnrdhlpbhnbjrhpfndlbkbldnfphrjbnhbplhdrnjfbqnkhebrpnljhfdbcfilorcioclcoicrolifcdjpdmdpjdekqeneqkeflrfofrlfgpghqhirijklmnopqr","aassrrqqppoonnmmllkkjjiihhggffeeddccbbacegikmoqsbdfhjlnpradgjmpscfilorbehknqaeimqbfjnrcgkosdhlpafkpbglqchmrdinsejoagmsflrekqdjpciobhnahocjqelsgnbipdkrfmaiqfnckshpembjrgodlajsirhqgpfoendmclbkakblcmdneofpgqhrisjaldogrjbmephskcnfqiamfrkdpibngsleqjcohanhboicpjdqkerlfsmgaojesnidrmhcqlgbpkfaplhdsokgcrnjfbqmieaqnkhebrolifcspmjgdarpnljhfdbsqomkigecabcdefghijklmnopqrs","aattssrrqqppoonnmmllkkjjiihhggffeeddccbbacegikmoqsadgjmpsbehknqtcfiloraeimqafkpagmsekqcioahobipcjqdkrelsfmtgnaiqemajshqfodmbktirgpenclakalcnepgritkbmdofqhsjameqiangtmfslerkdqjcpibohaoicqkesmgapkfaqmiearolifctqnkhebspmjgdasqomkigecabdfhjlnprtbfjnrbglqbhntflrdjpbjrfnblbnfrjbpjdrlftnhbqlgbrnjfbtrpnljhfdbcgkoschmrcksgocmcogskcrmhcsokgcdhlptdinsdlthpdndphtldsnidtplhdejoteoetojefpfgqghrhisijtjklmnopqrst","aauuttssrrqqppoonnmmllkkjjiihhggffeeddccbbacegikmoqsubdfhjlnprtadgjmpsaeimqudhlptcgkosbfjnrafkpuejotdinschmrbglqagmsdjpahoaiqdltgobjremuhpcksfnajsgpdmakujtishrgqfpeodncmblalbmcndoepfqgrhsitjukamdpgsjanfskcphumerjbogtldqiaohapjdsmgaqlgbrmhcsnidtojeupkfarnjfbsokgctplhduqmieaspmjgdatrpnljhfdbusqomkigecabehknqtbhntekqbipbkthqenbneqhtkbpibqketnhbtqnkhebcfiloruciouflrcjqcluirfocofriulcqjcrlfuoicurolifcdkrdrkdelseslefmtftmfgnugunghijklmnopqrstu","aavvuuttssrrqqppoonnmmllkkjjiihhggffeeddccbbacegikmoqsuadgjmpsvcfilorubehknqtaeimqucgkosafkpudinsbglqvejotchmragmsciouekqahovgnufmtelsdkrcjqbipaiqcksemugoajsfobktgpcluhqdmvirenakuisgqeocmalamcoeqgsiukanerivmdqhulcpgtkbofsjaogumeskcqiapibqjcrkdsletmfungvohaqkeuoicsmgarmhctojevqlgbsnidupkfasokgcuqmieatqnkheburolifcvspmjgdausqomkigecabdfhjlnprtvbfjnrvdhlptbhntdjpvflrbjrdltfnvhpblvjthrfpdnbmbndpfrhtjvlbphvnftldrjbrlfvpjdtnhbtplhdvrnjfbvtrpnljhfdbcncdodepefqfgrghshitijujkvklmnopqrstuv","aawwvvuuttssrrqqppoonnmmllkkjjiihhggffeeddccbbacegikmoqsuwbdfhjlnprtvadgjmpsvbehknqtwcfiloruaeimqubfjnrvcgkoswdhlptafkpuchmrwejotbglqvdinsagmsbhntcioudjpvekqwflrahovfmtdkrbipwgnuelscjqaiqbjrcksdltemufnvgowhpajsenwirdmvhqclugpbktfoakuhreoblvisfpcmwjtgqdnalwkvjuithsgrfqepdocnbmambncodpeqfrgshtiujvkwlandqgtjwmcpfsivlboerhukaoftkbpgulcqhvmdriwnesjaphwogvnfumetldskcrjbqiaqjcsleungwpibrkdtmfvoharlfwqkevpjduoictnhbsmgasnidvqlgbtojewrmhcupkfatplhdwsokgcvrnjfbuqmieaurolifcwtqnkhebvspmjgdavtrpnljhfdbwusqomkigecabcdefghijklmnopqrstuvw","aaxxwwvvuuttssrrqqppoonnmmllkkjjiihhggffeeddccbbacegikmoqsuwadgjmpsvaeimquafkpubglqvchmrwdinsxejotagmsahovelsbipwfmtcjqxgnudkraiqajsdmvgpakugqcmwiseoalwjuhsfqdobmxkvitgrepcnamancpergtivkxmbodqfshujwlaoesiwmcqgukapgvmdsjaqiarkdungxqjctmfwpibslevohasmgatojexsnidwrmhcvqlgbupkfauqmieavspmjgdawusqomkigecabdfhjlnprtvxbehknqtwbfjnrvbhntbjrbktenwhqblvhrdnxjtfpbnbpftjxndrhvlbqhwnetkbrjbtnhbvrnjfbwtqnkhebxvtrpnljhfdbcfiloruxcgkoswcioucksclufoxircocrixofulcskcuoicwsokgcxurolifcdhlptxdjpvdltdpdtldvpjdxtplhdekqwemueqeumewqkeflrxfnvfrfvnfxrlfgowgsgwoghpxhthxphiuijvjkwklxlmnopqrstuvwx","aayyxxwwvvuuttssrrqqppoonnmmllkkjjiihhggffeeddccbbacegikmoqsuwybdfhjlnprtvxadgjmpsvycfiloruxbehknqtwaeimquydhlptxcgkoswbfjnrvafkpuagmsyflrxekqwdjpvcioubhntahovdkrygnucjqxfmtbipwelsaiqyhpxgowfnvemudltcksbjrajscluenwgpyirbktdmvfoxhqakufpalwitfqcnykvhsepbmxjugrdoamylxkwjviuhtgsfreqdpcobnanbocpdqerfsgthuivjwkxlymaodrgujxmbpeshvkyncqftiwlapfukaqhxofvmdtkbriypgwneulcsjarjbskctldumevnfwogxphyqiaslewpibtmfxqjcungyrkdvohatnhbuoicvpjdwqkexrlfysmgaupkfavrnjfbwsokgcxtplhdyuqmieawtqnkhebxurolifcyvspmjgdaxvtrpnljhfdbywusqomkigecabglqvblvgqbqgvlbvqlgbchmrwcmwhrcrhwmcwrmhcdinsxdnxisdsixndxsnidejotyeoyjtetjyoeytojefghijklmnopqrstuvwxy","aazzyyxxwwvvuuttssrrqqppoonnmmllkkjjiihhggffeeddccbbacegikmoqsuwyadgjmpsvybehknqtwzcfiloruxaeimquycgkoswafkpuzejotydinsxchmrwbglqvagmsyekqwciouahovcjqxelszgnubipwdkryfmtaiqygowemucksajsbktcludmvenwfoxgpyhqzirakueoyiscmwgqalwhsdozkvgrcnyjufqbmxitepamykwiugseqcoanaocqesguiwkymapetixmbqfujyncrgvkzodshwlaqgwmcsiyoeukarizqhypgxofwnevmdulctkbsjaskcumewogyqiatmfyrkdwpibungzslexqjcvohauoicwqkeysmgavqlgbwrmhcxsnidytojezupkfawsokgcyuqmieaxurolifczwtqnkhebyvspmjgdaywusqomkigecabdfhjlnprtvxzbfjnrvzdhlptxbhntzflrxdjpvbjrzhpxfnvdltblvfpzjtdnxhrbnzlxjvhtfrdpbobpdrfthvjxlznbrhxndtjzpfvlbtldvnfxphzrjbvpjdxrlfztnhbxtplhdzvrnjfbzxvtrpnljhfdbcpcdqderefsfgtghuhivijwjkxklylmzmnopqrstuvwxyz" };

	while (ans.size() <= n) {
		for (auto now : vec[k - 1]) ans.push_back(now);
	}
	while (ans.size() > n) ans.pop_back();
	cout << ans;
	return 0;
}