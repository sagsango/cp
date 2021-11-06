// https://leetcode.com/problems/design-twitter/

// TODO: Think Better approach, based on what will be frequency of each operation.
// Note : no of follwer, also vary, we can make diffrent solutions according to that.
// Maximum no of follwers can be 95M, Cristiano Ronaldo.

class Twitter {
	// two list 1 -> persons news feed ( 10 most recent )
	//          2 -> persons tweets ( 10 most recent )
	public:
		Twitter() {

		}
		void postTweet(int userId, int tweetId) {
			// add this tweet to user + follwers news feed, as most recent.
			// O( no of followers =  total users = n )
		}

		vector<int> getNewsFeed(int userId) {
			// return user'd news feed
			// O(1)
		}

		void follow(int followerId, int followeeId) {
			// merge two sorted, news feeds
			// follower's news feed = merge( user's , followee's ) news feed
			// O(mi + mj = 10 )
		}

		void unfollow(int followerId, int followeeId) {
			// recreate follwers news feed with,
			// his + all followed persons news feed.
			// O( 10 * log(no of ppl followed) = 10 * log(all users) )
			// mergeing the tweet list of his + all followed ppl.
		}
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
