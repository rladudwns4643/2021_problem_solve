using namespace std;

long long solution(int price, int money, int count)
{
    long long answer{ 0 };
    long long t{ 0 };
    for (int i = count; i > 0; --i) {
        t += i;
    }
    answer = (money - (price * t));
    if (answer > 0) {
        return 0;
    }
    else {
        return answer * -1;
    }
}