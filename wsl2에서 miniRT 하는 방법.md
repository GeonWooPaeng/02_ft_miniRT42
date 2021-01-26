# wsl2에서 miniRT 하는 방법 



<br/>



Xwindow(X11)는 Unix/Linux 계열의 운영체제에서 사용되는 GUI 환경 구현을 위한 시스템
- 네트워크 기반의 클라이언트 - 서버 방식으로 동작 
=> 프로그램이 GUI 창을 띄어 달라고 X server에 요청하면 X server가 요청을 처리하여 GUI 창을 띄운다.



<br/>



## 1. 설치 



<br/>



- 설치 파일 -
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html (잘보기)
1. vcxsrv 설치
https://sourceforge.net/projects/vcxsrv/
2. xming 설치



<br/>



## 2. 방화벽 풀기



<br/>



- 방화벽 설정 -
1. 방화벽 빛 네트워크 보호
2. 고급설정
3. 인바운드/아웃바운드 규칙(두개다 해야 좋습니다.)
4. 새 규칙
5. 프로그램
6. 프로그램 경로에 :\Program Files\VcXsrv\vcxsrv.exe (선 확인)
7. 연결 허용
8. 계속 다음



<br/>



---------------------------------------------------



## 3. 필요 함수 설치 



<br/>



wsl2에서 실행을 하기 위해서 subject에서 주는 파일 대신
https://github.com/42Paris/minilibx-linux 를 clone 해줍니다.

<br/>



---------------------------------------------------



<br/>



## 4. ip 설정



<br/>



```shell
$ip route #에서 default값이 나의 네트워크 ip(default gateway)
$echo $DISPLAY # default gateway랑 같은지 확인
$export $DISPLAY=나의 네트워크 값 #default gateway랑 같지 않은 경우
```



<br/>



## - 편안하게 compile 하기 - 



<br/>



sudo mkdir /usr/local/man/man1
sudo cp man/man1/* /usr/local/man/man1/
sudo cp libmlx.a /usr/local/lib/
sudo cp mlx.h /usr/local/include/
=> 이것을 해줘서 -L -I를 생략할 수 있습니다.



<br/>



실행을 하기 전에 gcc main.c -lbsd -lmlx -lXext -lX11 -lm 을 해주자
-L 라이브러리를 쓸 폴더 추가
-I include 폴더 추가
-lm : math 라이브러리를 추가

#include <> : 라이브러리를 include 할때 주로 사용 



<br/>



----------------------------

## 5. 확인 Test



<br/>



```shell
$cd minilibx-linux 
$make 
$cd test
$./mlx-test 
```



<br/>



- 동료 jleem의 도움이 큽니다.