//
//  main.cpp
//  Substring with Concatenation of All Words
//
//  Created by Renchu Song on 14/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	// Naive Solution: TLE
	void helper(string &S, vector<string> &L, bool* visit, int d, int n, string str, vector<int> &result) {
		if (d == n) {
			int pos = (int)S.find(str);
			while (pos != string::npos) {
				result.push_back(pos);
				pos = (int)S.find(str, pos + 1);
			}
			return;
		}
		for (int i = 0; i < n; ++i)
			if (!visit[i]) {
				visit[i] = true;
				helper(S, L, visit, d + 1, n, str + L[i], result);
				visit[i] = false;
			}
	}
	
    vector<int> findSubstringNaive(string S, vector<string> &L) {
		int n = (int)L.size();
		bool visit[n];
		memset(visit, false, sizeof(visit));
		vector<int> result;
		helper(S, L, visit, 0, n, "", result);
		
		unique(result.begin(), result.end());
		sort(result.begin(), result.end());
		return result;
    }
	
	// Better Solution
	int w = 0;	// len of word

	vector<int> findSubstring(string S, vector<string> &L) {
		int n = (int)S.size(), m = (int)L.size();
		w = (int)L[0].length();
		
		vector<int> result;
		
		int exist[n + 1];
		
		int fre[m + 1], has[m + 1];
		memset(exist, 0, sizeof(exist));
		
		map<string, int> count;
		
		for (string str: L) ++count[str];
		int t = 0;
		memset(exist, 255, sizeof(exist));
		for (map<string, int>::iterator it = count.begin(); it != count.end(); ++it, ++t) {
			fre[t] = (*it).second;
			string str = (*it).first;
			int pos = (int)S.find(str);
			while (pos != string::npos) {
				exist[pos] = t;
				pos = (int)S.find(str, pos + 1);
			}
		}
		
		for (int pos = 0; pos < w; ++pos) {
			int loc = pos;
			int remain = t;
			memset(has, 0, sizeof(has));
			for (int i = loc; i < n; i += w) {
				if (exist[i] > -1) {
					++has[exist[i]];
					if (has[exist[i]] == fre[exist[i]]) --remain;
				}

				while (exist[loc] < 0 || (exist[loc] > -1 && has[exist[loc]] > fre[exist[loc]])) {
					if (loc >= i) break;
					if (exist[loc] > -1) --has[exist[loc]];
					loc += w;
				}
				if ((i - loc) == (m - 1) * w && remain == 0) result.push_back(loc);
			}
		}
		
		unique(result.begin(), result.end());
		sort(result.begin(), result.end());
		return result;
    }
};

int main(int argc, const char * argv[])
{
	
	vector<string> m {"dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"};
	vector<int> result = (new Solution())->findSubstring("pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel", m);

//	vector<string> m {"foo", "bar"};
//	vector<int> result = (new Solution())->findSubstring("barfoothefoobarman", m);

//	vector<string> m {"ab","ba","ab","ba"};
//	vector<int> result = (new Solution())->findSubstring("abaababbaba", m);

	clock_t t = clock();
//	vector<string> m {"vkyprpobkmsfzucyqzzfoafhyzca","gdvrupgnickwasnmjkouwvpegsgi","jzukeuphzuaityuhuvtaeyewpiih","syzqcnhfsbsdkalkyswuzzugfnrw","kygdtbrualfnleljxlclgfokqmas","pqoqebuckqhuuhtbqdfgmghlmwuq","ycrgpnqellshycigpjjycgwcumhx","vgogruifovqohxcdrjwroyazyfcm","lefxclawpssrdzerdrccffplkdxa","vyqhgvsvnjeciuhfazheupabuovy","fexbifznmmmgjkpxujkgpzrfyjfj","qthyvbpfnfwvycrzjhmeyvaogbop","rvvmbwsilazwwraroscbejyqcwbl","jzlafxodqxbpqsrviblaypnkmeyy","vrhzoqonyhhjotbhaptusljivfbr","trfvxektbhzilblororbyqcworpj","sybwxuozvleuiemfeqizmpeqxvzp","bxgdqeqawpblyyukmlarvzcitelf","tjxgahonlxwtcwxkpyuguaffktls","ebhyfvqjdjtzbspbkeuvcduxxhoy","rplhkfahmoqhaadszcjblctweonx","obxfaflsdlhdmxylrhdwykzavkch","hykrzhpevomytkehvbknbcgdmaky","tuvbtdssvcqwcvuslqdmsyjydufm","bkmtlhwrjyzyyddtbatzcidxbjzc","nrigldjggdadftzkotezlimeixel","tjqkgooiltthpzrdzefeuexocpzx","astpnufhcyhoivivxwphisiihvwz","plashuyjiesnbrqvhzkgxmlrmbho","ieaqcmstuwgffwdrshvlokbkjnjt","dewtgblfjkwcyvrravvjeiujaasv","hzeuvdirbumdcyhxvizqaspygypr","bbupkrinqdgjgvrlhdcsznylcynb","mwzmuyjvbijetxzatsszvmjrjqvw","lsxqakjrgasvjyjlowpcftohhuww","datwhkivbboennizwyovjwyonhvp","stuaudeckfedowdivplwbihqtpnx","chkctzauasvmkrsjaoprxzrrislk","sypcigotuopynwaoeyeqfibnuwyn","izwydmyiddxgojubqystzhtfmiof","rsrvmbrtlhkqvlfqfhnrcgnulqlc","tmfhkhutgxuwqxzvthbktergieip","kmpannhpuskxdrcrocfhkkdkvemq","pvyorisykimukboukjdbankosjpp","fahqbehiccxdwctcrrvuekrbkuok","nuuomzahttqkdndpdvwihzkknmxb","agpngnngkpsscbinvjbmjqbfsypt","zcbadxppoaeedlplihwqmzkoojbq","bgwnuxwefccdapcdkkxyvyptszoc","xzeszyrceeecuxmfsbxxnvyhalhu","evhpzgrskhlsrfmmrdqpqhwswelf","euithiooeoznstcvmsttsdbrrojd","ibdqmkcwrsnumdeyokzukqlushyo","babjxuqwfxaztvotnjqubmtcukts","kqjtsfdybufbqhlliiucdndjmhfd","csynisxanjxhkmrqfhylnszckigb","dtsecofjdxxasqhoxwcfuyqnbbnu","owkqffjiuctbhvweiybxmoxlisvv","kbxpfwtpbscqgpwrbnovwadlauty","nepadpepdjkomgepbzpageogtzkd","mmhnqadomhcbmwkmlgrneksazicq","rjgiafldvqxxcfujzptmnwnqfxdy","tgoxkvvptnawxvxanmbzrvuvaoua","oyalizczorcafuiepkdhlcmberie","wcnqcdsnljggxxemuhaafgskovak","tfcfchqhbbhmcpssduhfaljxdjtl","gdryqmitkpmzlrrkatuvmyaaqosd","zmhpnayyeggeqmkzwjyjrgezdweg","qflmwtjvztpacqkqsvellvommqia","rbhhafnwptozpkzshttdhtndhzzt","kqmxzeqirbvclxyhbxcuxuodlfil","epnbyezmlcalkfnkovaeydkixqsa","crczptixoatdlziutpbtqjzlaamu","avclbeabrswvvrhtzrildlwgbind","jbxctcorhjustkrewkpgcngtgodc","xwhefcqlhcnsihvgookjodzyxodc","vgmkhcjaegpzmalquakxknyvbojm","pjlhkvomadlrwzrnlsfsnayxtlad","rzheqwzoyzotzuhsfqfbailzkzkg","pbnzqcupteijdunudkdyjmqnjnxk","zxxdfwewhquwnupslmjbsroblzuu","zselvsrhoivrmoqgeldcdlakomfo","qjamzfvbuamftloiiyvbncrekvol","xyowodjulaxolcsnhsuzbptowtxz","puuaisjoluoiyzlnkjeulwlpliuj","dpzgcidailgxkvyaejjpivaqmpsk","mfbmwynonsyqpleatbmfhcgydkrl","qhpmmrrqbkzcliqnxihcfpjhcseh","pflktfyvnllruiwigexwsnaydqcw","mdedcacwrxxmeupejjzlcjeaqxpr","bnhwyageowozqjihjzmigrpaymqc","njsqglllijcwubytryptgrrfyype","moyhhigwywlxdtirojzoyuisiudd","gaxogxhijbbfyildgqwbzrondpzn","qpryukxkwhfgzuiklzwnurkhpkjf","rjzljakguagrmmlwszdxqlyeacuy","eivkgdkckgrbwhtbtytpkspdeyru","ikhkkfnrbunkmjgzfxrrkcuctifg","sdmscgtjvqxoxsprjvjzvunpzkqq","mywyzwcmikjplszmrammwcvizzjw","ixlcricllgqymubcsfmowxkzirrb","ahtrdntlhczsxncxonlyxrvkngab","lruntsuvmyiplowalkfvgibcaeiq","wqpnefqddjebadagpjtulhyjaovn","eiwzollynvytdpvrpghlgulthjol","tqfjzpfljszinvilqphopfejzpih","gnuknxvmulkbilbbirwwaoqdbmhx","ypouajvtsilpihkajobwvrviyhih","smlxvwawfweprbkghwouzfjsawmc","uvvuujswyovpkjdidhkjveoqvfbi","vyswdflcyptilsmrdmybrckasuvr","avnrfmeomqxjrfcfrqbjpfihsglt","rpdmydtakjqxjmtliqxaqrgkunqe","pmqbzwszwpzygmhkdcmdxtqmlhby","vvcejrnhqusawvrxwiyddulyjuxi","aounisgiepbkpthbtrmipbmuwcdg","nlhxitreyrjwbxwyxritnacahfcb","wivbthksxawvsbbynhowlgmahrzd","zxyptkiyprijwcndxjjhhmgvbeij","zgkytrpgtpgxxmcoaopwynhrtmqz","zgtbfppoxvrfuhongwujtblxqmyg","kvkuvdxdykoyvyuiwwqgmgdasydj","jouksvkvubmidtoiegtonqgbrrrf","yjnwbbsbmpuexhufpgiaujyratza","zflnytcpjwzegkyfwfejgnivzadk","eksafuanoibrmmdtavbcmxmizcjz","qyrilcggaieggkxzlhhvgvrfcbac","ayvliqyoycyunbgobcggcfgqhqvp","wqbeuwxoofeyiquijhwutnorkfvq","lgkjxzaffftnjlfamvoucfurecpj","yxzxzbwoalmtgvsqedsiuwhdlrcg","pdcblomjqnovukidvpgikwepebgi","lwaqmptmwsajwaxifktvitbgwlqv","zlnewjtfhcaxghjeqhzzzepgebvx","jowjfqjyveldplwricppcnwevsnk","hcnedrzcsqfwulyqlnwdovcbsaks","kwfjdrjylageqocncgdcusaughnb","mlgpzyxyaoliertcytgnosoplppp","nvstvhlitkktszzpzirqjbvptgxl","ccyfctbldlghpulckwdgusbfobtd","faqqsepulfecjzgwzfdaehubbkeo","dgksrupzpjfoaomdnjekamepngpw","dosfyaplgqelvhzemtjbatzybxxb","bbirsbqnlpzkyfsxbcimeebyxmhm","kirkjmytcwhcbiyojeelimtkracy","yruzsctlglytaxfyeyyfcgtgmxfk","fxtfxlfeswtoaqtwhsuzzhqrwusc","xzczpxnxrthxkijbeqcxhphysvur","itvwfelxfontyqvkohyznrmuchub","fwiwobucdnyowketvjlctzuvhjrt","awtohiebhyqhrxhhdvgaepzbnqvm","mbybkmixhyjjbwbavunjmvbzvbwr","ywbjpllitgeoiedmzwcwccpyaexa","pgwxhzqtmsrdkhyykewyrvubnhxi","iricritvvaandssoveatwynxxjdf","zexedfdrhzwkmuakghdbsrelsaib","ypppiefofbqsrzooihpymwgyfnmr","lknqszsnythaneoxxghxvypsxilh","rocxqunjycflkjqtkwpjbsjfbggd","qmtibvhtpucqyjbisrbfosopmaxo","nrmvwczztyelqljnwkdhxzmlwoop","vosmaimocjxcoxgnooqdeqqeqtek","exssazvezxaquyebuthdegrgrvii","yzrbfnwlqhtbrrgqoxjouexyprjr","hpnvxqktoxjerhugvzjqcvxjzfhc","ifapansscavkwfkokkdldojgcmnj","gmmjyzejicarabpbeuuivphxxkwa","mtgnqosivkjtzmfxmzjznkqilvsg","aeroymcmneuiamudaytftpncqapd","ovwebudjwveioynafnzrsxrltmmi","litldiekwibkzavsfyxyoajdhsna","wkkpzxwlcztrnjynldhmiqnvvgrz","szuddaainaeeswvywbpbvtgayvnk","kkxgomfmfrmbcoshmehgyaymecbu","dimhznnbwsdegmdqheqnnzfxwfqi","xqvqfazpiuiqrdphcqevzfgsmzau","eamqlmybygnexahzobidfplgsjsy","pytxsrvzvhxaxmuvcrhryhsnzfhb","wegvdhnxrvxjoiskmfnloysylzvm","xezvuaaoyzfmfjknzgxkowgjlubv","pafqzizotmxntddbjhnifrghtxhw","lxzemmfukbuocsvyzfnoankejjmr","rpnbgwwadzyfwfimovawduziierw","rozddodsbmivesuklybbbgintnxo","izrokmqrgseubhontrhwokyahmii","ojvtaxsrsdpidkmplulejmzcxznz","diwphyhtochmwhvujsdofymptnvp","dildbhtgjvvtpgmglbpptvksasmo","rmoyluuhyfabzpgbnpykyadasuya","ojktkrlnxvwzxtfuvayosuiygzzs","ugbehmgolwsbtvslnjgvkrylinvv","mcoemwoobcrwuovxwqgxfbmuzzne","aowysnfhbxnolhvjkdqbpzbthxyc","mgejpsrgnzodvercdtfuedoueotc","fyiatfuproopflfpukzarmjmqxfl","zwoycnuxpwnnvsccdorfvprlnyuy","ckiimfytdfbmhfsfpfkvxgyxzmmd","kytbhtnjakkulwagkqquomvbomhy","dxttdxwomkzczqxuaizxxhfkembi","fvkcspgbgwkyqeamzrlyblbghogs","wcpzxrkyvkcpfykarutslbdpocxs","enregkvvebcgbmxlhfggewomqywa","iyfrzsiybadwqpwjzcsxdfkhhrkv","wfyurkkthgejhzawkbjxeskolxjg","xyraghpnueveupxyshlpqoebehiy","gbheihzzrjsarzjbymxlpjivbsko","pzyguhgpkvwxbuuzwmahtomukoks","tsbagsgodcjjfosiaptjwcqaagos","ljgaotljyjgnwshsafaijzfdmfcs"};
//	vector<int> result = (new Solution())->findSubstring("aratdgpfsookqyxiptwjllwirwmfdmafdayignqadektejbvcaepnbyezmlcalkfnkovaeydkixqsalwaqmptmwsajwaxifktvitbgwlqvdiwphyhtochmwhvujsdofymptnvpzlnewjtfhcaxghjeqhzzzepgebvxpqoqebuckqhuuhtbqdfgmghlmwuqypppiefofbqsrzooihpymwgyfnmrlgkjxzaffftnjlfamvoucfurecpjpdcblomjqnovukidvpgikwepebgidxttdxwomkzczqxuaizxxhfkembinjsqglllijcwubytryptgrrfyypekqmxzeqirbvclxyhbxcuxuodlfilfaqqsepulfecjzgwzfdaehubbkeorocxqunjycflkjqtkwpjbsjfbggdqmtibvhtpucqyjbisrbfosopmaxogdryqmitkpmzlrrkatuvmyaaqosdqpryukxkwhfgzuiklzwnurkhpkjfbbirsbqnlpzkyfsxbcimeebyxmhmyruzsctlglytaxfyeyyfcgtgmxfkjowjfqjyveldplwricppcnwevsnkpuuaisjoluoiyzlnkjeulwlpliujahtrdntlhczsxncxonlyxrvkngabowkqffjiuctbhvweiybxmoxlisvvzxyptkiyprijwcndxjjhhmgvbeijwegvdhnxrvxjoiskmfnloysylzvmfexbifznmmmgjkpxujkgpzrfyjfjkbxpfwtpbscqgpwrbnovwadlautyfahqbehiccxdwctcrrvuekrbkuokojktkrlnxvwzxtfuvayosuiygzzstqfjzpfljszinvilqphopfejzpihqjamzfvbuamftloiiyvbncrekvolkytbhtnjakkulwagkqquomvbomhykvkuvdxdykoyvyuiwwqgmgdasydjnlhxitreyrjwbxwyxritnacahfcbdgksrupzpjfoaomdnjekamepngpwlsxqakjrgasvjyjlowpcftohhuwwaounisgiepbkpthbtrmipbmuwcdgxzczpxnxrthxkijbeqcxhphysvuryxzxzbwoalmtgvsqedsiuwhdlrcgmwzmuyjvbijetxzatsszvmjrjqvwhzeuvdirbumdcyhxvizqaspygyprrmoyluuhyfabzpgbnpykyadasuyavosmaimocjxcoxgnooqdeqqeqtekpflktfyvnllruiwigexwsnaydqcwljgaotljyjgnwshsafaijzfdmfcsvgogruifovqohxcdrjwroyazyfcmmgejpsrgnzodvercdtfuedoueotcvyqhgvsvnjeciuhfazheupabuovycrczptixoatdlziutpbtqjzlaamuojvtaxsrsdpidkmplulejmzcxznzbbupkrinqdgjgvrlhdcsznylcynbzcbadxppoaeedlplihwqmzkoojbqjouksvkvubmidtoiegtonqgbrrrfcsynisxanjxhkmrqfhylnszckigbbxgdqeqawpblyyukmlarvzcitelfmtgnqosivkjtzmfxmzjznkqilvsgzflnytcpjwzegkyfwfejgnivzadkvyswdflcyptilsmrdmybrckasuvrxzeszyrceeecuxmfsbxxnvyhalhuhcnedrzcsqfwulyqlnwdovcbsaksnrmvwczztyelqljnwkdhxzmlwooprzheqwzoyzotzuhsfqfbailzkzkgobxfaflsdlhdmxylrhdwykzavkchkmpannhpuskxdrcrocfhkkdkvemqrozddodsbmivesuklybbbgintnxorjgiafldvqxxcfujzptmnwnqfxdymcoemwoobcrwuovxwqgxfbmuzznezselvsrhoivrmoqgeldcdlakomfonuuomzahttqkdndpdvwihzkknmxbaeroymcmneuiamudaytftpncqapdmmhnqadomhcbmwkmlgrneksazicqitvwfelxfontyqvkohyznrmuchubpytxsrvzvhxaxmuvcrhryhsnzfhbmdedcacwrxxmeupejjzlcjeaqxprexssazvezxaquyebuthdegrgrviisybwxuozvleuiemfeqizmpeqxvzprjzljakguagrmmlwszdxqlyeacuyavnrfmeomqxjrfcfrqbjpfihsgltlitldiekwibkzavsfyxyoajdhsnaayvliqyoycyunbgobcggcfgqhqvpkirkjmytcwhcbiyojeelimtkracysypcigotuopynwaoeyeqfibnuwynwcnqcdsnljggxxemuhaafgskovaksyzqcnhfsbsdkalkyswuzzugfnrwiricritvvaandssoveatwynxxjdfywbjpllitgeoiedmzwcwccpyaexapafqzizotmxntddbjhnifrghtxhwdewtgblfjkwcyvrravvjeiujaasvyzrbfnwlqhtbrrgqoxjouexyprjrsdmscgtjvqxoxsprjvjzvunpzkqqebhyfvqjdjtzbspbkeuvcduxxhoytgoxkvvptnawxvxanmbzrvuvaouavkyprpobkmsfzucyqzzfoafhyzcaoyalizczorcafuiepkdhlcmberietmfhkhutgxuwqxzvthbktergieipxqvqfazpiuiqrdphcqevzfgsmzaudildbhtgjvvtpgmglbpptvksasmosmlxvwawfweprbkghwouzfjsawmcqyrilcggaieggkxzlhhvgvrfcbaczmhpnayyeggeqmkzwjyjrgezdwegzgkytrpgtpgxxmcoaopwynhrtmqzkwfjdrjylageqocncgdcusaughnbtfcfchqhbbhmcpssduhfaljxdjtlqhpmmrrqbkzcliqnxihcfpjhcsehdatwhkivbboennizwyovjwyonhvpccyfctbldlghpulckwdgusbfobtdlruntsuvmyiplowalkfvgibcaeiqgdvrupgnickwasnmjkouwvpegsgiwqbeuwxoofeyiquijhwutnorkfvqxezvuaaoyzfmfjknzgxkowgjlubvzwoycnuxpwnnvsccdorfvprlnyuyuvvuujswyovpkjdidhkjveoqvfbifyiatfuproopflfpukzarmjmqxfleivkgdkckgrbwhtbtytpkspdeyruxwhefcqlhcnsihvgookjodzyxodcpvyorisykimukboukjdbankosjppastpnufhcyhoivivxwphisiihvwzenregkvvebcgbmxlhfggewomqywatsbagsgodcjjfosiaptjwcqaagoseksafuanoibrmmdtavbcmxmizcjzizrokmqrgseubhontrhwokyahmiiqthyvbpfnfwvycrzjhmeyvaogboppzyguhgpkvwxbuuzwmahtomukoksrbhhafnwptozpkzshttdhtndhzztpjlhkvomadlrwzrnlsfsnayxtladmbybkmixhyjjbwbavunjmvbzvbwrmywyzwcmikjplszmrammwcvizzjwagpngnngkpsscbinvjbmjqbfsyptxyraghpnueveupxyshlpqoebehiyfxtfxlfeswtoaqtwhsuzzhqrwuscbabjxuqwfxaztvotnjqubmtcuktsgnuknxvmulkbilbbirwwaoqdbmhxycrgpnqellshycigpjjycgwcumhxaowysnfhbxnolhvjkdqbpzbthxycmfbmwynonsyqpleatbmfhcgydkrlhpnvxqktoxjerhugvzjqcvxjzfhcpbnzqcupteijdunudkdyjmqnjnxkvgmkhcjaegpzmalquakxknyvbojmeiwzollynvytdpvrpghlgulthjolzxxdfwewhquwnupslmjbsroblzuuikhkkfnrbunkmjgzfxrrkcuctifgibdqmkcwrsnumdeyokzukqlushyopgwxhzqtmsrdkhyykewyrvubnhxiovwebudjwveioynafnzrsxrltmmitjqkgooiltthpzrdzefeuexocpzxbnhwyageowozqjihjzmigrpaymqcdpzgcidailgxkvyaejjpivaqmpskdimhznnbwsdegmdqheqnnzfxwfqiwivbthksxawvsbbynhowlgmahrzdypouajvtsilpihkajobwvrviyhihyjnwbbsbmpuexhufpgiaujyratzachkctzauasvmkrsjaoprxzrrislklknqszsnythaneoxxghxvypsxilhawtohiebhyqhrxhhdvgaepzbnqvmzgtbfppoxvrfuhongwujtblxqmygdtsecofjdxxasqhoxwcfuyqnbbnuplashuyjiesnbrqvhzkgxmlrmbhoeuithiooeoznstcvmsttsdbrrojdrsrvmbrtlhkqvlfqfhnrcgnulqlcfwiwobucdnyowketvjlctzuvhjrtzexedfdrhzwkmuakghdbsrelsaibjzukeuphzuaityuhuvtaeyewpiihkqjtsfdybufbqhlliiucdndjmhfdrpnbgwwadzyfwfimovawduziierwlxzemmfukbuocsvyzfnoankejjmrnepadpepdjkomgepbzpageogtzkdizwydmyiddxgojubqystzhtfmiofhykrzhpevomytkehvbknbcgdmakyiyfrzsiybadwqpwjzcsxdfkhhrkvtuvbtdssvcqwcvuslqdmsyjydufmnrigldjggdadftzkotezlimeixeltjxgahonlxwtcwxkpyuguaffktlsrpdmydtakjqxjmtliqxaqrgkunqejbxctcorhjustkrewkpgcngtgodcevhpzgrskhlsrfmmrdqpqhwswelfvrhzoqonyhhjotbhaptusljivfbrmoyhhigwywlxdtirojzoyuisiuddbgwnuxwefccdapcdkkxyvyptszoctrfvxektbhzilblororbyqcworpjqflmwtjvztpacqkqsvellvommqiajzlafxodqxbpqsrviblaypnkmeyyugbehmgolwsbtvslnjgvkrylinvvrvvmbwsilazwwraroscbejyqcwblkygdtbrualfnleljxlclgfokqmaslefxclawpssrdzerdrccffplkdxaszuddaainaeeswvywbpbvtgayvnkbkmtlhwrjyzyyddtbatzcidxbjzcgmmjyzejicarabpbeuuivphxxkwavvcejrnhqusawvrxwiyddulyjuxifvkcspgbgwkyqeamzrlyblbghogsifapansscavkwfkokkdldojgcmnjavclbeabrswvvrhtzrildlwgbindwcpzxrkyvkcpfykarutslbdpocxskkxgomfmfrmbcoshmehgyaymecbueamqlmybygnexahzobidfplgsjsynvstvhlitkktszzpzirqjbvptgxlrplhkfahmoqhaadszcjblctweonxwkkpzxwlcztrnjynldhmiqnvvgrzwfyurkkthgejhzawkbjxeskolxjggbheihzzrjsarzjbymxlpjivbskostuaudeckfedowdivplwbihqtpnxixlcricllgqymubcsfmowxkzirrbieaqcmstuwgffwdrshvlokbkjnjtgaxogxhijbbfyildgqwbzrondpznckiimfytdfbmhfsfpfkvxgyxzmmddosfyaplgqelvhzemtjbatzybxxbmlgpzyxyaoliertcytgnosoplppppmqbzwszwpzygmhkdcmdxtqmlhbywqpnefqddjebadagpjtulhyjaovnxyowodjulaxolcsnhsuzbptowtxziuohscdiinctpcjagbnnvjoyaknxdkynfmvzryiznmscodewfumafazgmodsydhfpcfgdpfsdzxudbqkvcmbdnjrbmjarrhgvonafut", m);
	
	for (int i : result) cout << i << endl;
	cout << clock() - t << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

