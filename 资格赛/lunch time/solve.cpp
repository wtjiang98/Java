#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 200010

using namespace std;

int score[MAXN];
int cost[MAXN];

int in[MAXN];
int out[MAXN];

int dp[MAXN];
vector<int> record[MAXN];
vector<int> cost_id[MAXN];


void init() {
	for (int i = 0; i < MAXN; i++) {
		dp[i] = 0;
		score[i] = 0;
		cost[i] = 0;
		record[i].clear();
		cost_id[i].clear();
	}
}


bool isRepeat(int m, int n) {
    if (n == 0) {
        return false;
    }
    for (int i = 0; i < record[m].size(); i++) {
        if (record[m][i] == n) {
            return true;
        }
    }

    return false;
}

bool isSmaller(int current, int candidate, int id) {
    int sum_current = 0, sum_candidate = id;

    for (int i = 0; i < record[current].size(); i++) {
        sum_current += record[current][i];
    }
    for (int i = 0; i < record[candidate].size(); i++) {
        sum_candidate += record[candidate][i];
    }

    if (sum_candidate < sum_current) {
        return true;
    }
    return false;
}

int main() {
	int T;
	freopen("0.in.clm", "r", stdin);
	freopen("0.out", "w", stdout);

	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {

		printf("Case #%d:\n", t);
		init();

		int n, budget;
		scanf("%d", &budget);
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &score[i], &cost[i]);
			cost_id[cost[i]].push_back(i);
		}

		for (int i = 0; i <= budget; i++) {
            for (int j = 0; j <= i; j++) {
                for (int k = 0; k < cost_id[j].size(); k++) {
                    if (cost_id[j].size() > 0 && k == cost_id[j].size()) {
                        break;
                    }

                    int id = 0;
                    if (cost_id[j].size() > 0) {
                        id = cost_id[j][k];
                    }

                    int tmp = dp[i - j] + score[id];
                    if (!isRepeat(i - j, id)) {
                        if (tmp > dp[i] || (tmp == dp[i] && isSmaller(i, i - j, id))) {
                            dp[i] = tmp;
                            if (i != i - j) {
                                record[i].clear();
                                record[i] = record[i - j];
                            }

                            if (id != 0) {
                                record[i].push_back(id);
                            }
                        }
                    }
                }
            }
		}

		printf("%d\n", dp[budget]);

        sort(record[budget].begin(), record[budget].end());
        for (int i = 0; i < record[budget].size(); i++) {
            printf("%d", record[budget][i]);
            if (i != record[budget].size() - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }

        printf("\n");
	}
	return 0;
}
