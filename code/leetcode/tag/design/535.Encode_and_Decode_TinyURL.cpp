// https://leetcode.com/problems/encode-and-decode-tinyurl/

class Solution {
	public:

		string base="0123456789abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";   // for encoding
		unordered_map<string,string>m;                   //maping encodings and longUrl
		string encode(string longUrl) {
			string enc="";
			while(true)
			{
				enc+=base[rand()%62];
				if(m.find(enc)==m.end())  //looking for an encode which is not present in the map
					break;
			}
			m[enc]=longUrl;      //maping
			return enc;
		}

		// Decodes a shortened URL to its original URL.
		string decode(string shortUrl) {
			return m[shortUrl];
		}

};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));




class Solution {
	map<string,string>url_id;
	map<string,string>id_url;
	int cnt;
	public:
	Solution(){
		url_id.clear();
		id_url.clear();
	}


	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		if( url_id.find(longUrl) == url_id.end() ){
			string id = "http://" + to_string(++cnt);
			url_id[longUrl]=id;
			id_url[id]=longUrl;
		}
		return url_id[longUrl];

	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl){
		return id_url[shortUrl];

	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
