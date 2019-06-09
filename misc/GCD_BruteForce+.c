int get_gcd(int a,int b)
{
    int max_div = 1;      //가장 큰 공약수를 저장할 변수
    int range = min(a, b);//두 수 중 작은 값 까지만 조사
    for(int i=range; i>=1; i--)
    { //i부터 공약수를 찾는다.
        if( a % i == 0 && b % i == 0)
        { // 두 수 모두의 약수일 경우
            max_div = i;  //저장 후 탈출
            break; //i는 점점 감소하므로, 더이상 볼 필요가 없다.
        }
    }
    return max_div;
}

int main() {

    int a, b;

    printf("Input two numbers:\n");

    scanf("%d %d", &a, &b);

    printf("Greatest common divisor: %d\n", GCD(a, b));

}
