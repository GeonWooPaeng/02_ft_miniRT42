# Ray_Tracing



<br/>

- 이미지의 픽셀 하나하나를 통과하는 광선들이 있다는 가정하에 그 광선(Ray)을 역추적(Trace)하는 방식

<br/>



## Physically Based Rendering



<br/>

- light ray를 다 추적하는 것
- light -> reflection -> pixel



<br/>



![physically_Based rendering](https://user-images.githubusercontent.com/53526987/106742857-eb916500-6660-11eb-9c9b-07c9607a0895.PNG)



<br/>

- light ray 와 material 과의 상호작용에 의해서 color가 결정된다.

<br/>

### shading

<br/>

- 음영(3차원 형태로 나오게 하는 것)

<br/>

### Shadow(그림자)

<br/>

- 바닥과 그 위에 물체가 있을 경우 광원으로 부터 나온 빛이 도달하지 않는 영역
- 그림자가 없으면 물체가 떠있는지 바닥에 붙어있는지 파악할 수 없다

<br/>





--------------------------------------------------------------





<br/>

## Backward Ray Tracing

<br/>

- camera(eye)로 부터 light, 물체로 빛(ray)를 쏘는 것
- pixel -> reflection -> light

<br/>

![backward_ray_tracing](https://user-images.githubusercontent.com/53526987/106743316-8ee27a00-6661-11eb-9e7e-a4c8bfb0e7f8.PNG)

<br/>

- 눈에 들어오는 것만 추적을 하여 모든 ray를 추적하는 것보다 효율적
- 투명, 반짝인 물체일 경우 오류 발생 => 혼합해서 사용

<br/>

### Shadow(그림자)

<br/>

- Shadow ray를 광원에 대해서 쐈을 때 막혀있으면 그림자가 된다.

<br/>





----------------------------------





<br/>

## Ray, Object

<br/>

- 직선의 방정식을 이용해서 ray의 위치를 표현 할 수 있다.
- t값을 변형해가며 물체와 ray가 충돌하는 위치를 찾을 수 있다.

<br/>

![ray_object](https://user-images.githubusercontent.com/53526987/106744174-c140a700-6662-11eb-91cb-96703d3cff92.png)

<br/>

- P(pixel): 시작점
- t: 선 위의 점을 표현한 parameter
- collision: 충돌(물리적으로 부딪친다.)
- intersection: 기하학적 의미에 가깝다(교차) => collision에 포함된다.

<br/>

### d(ray)는 단위 벡터 입니다. 

- 크기가 1이 아니면 color 값이 변형될 수 있기 때문
- 그래서 |P(pixel) - P(camera)|로 나눠준 것입니다. 

<br/>

### Ray로 부터 물체와 교차하는 방법

<br/>

- Ray를 쪼개서 쪼갠 만큼 이동하여 물체와 교차하는 지점을 찾는다.

<br/>





----------------------------------





<br/>

## Implicit Surface

<br/>

- 어떤 주요 material을 함수 f(x)로 표현하고 f(x)에 값(p(n))을 넣었을 때를 파악
- f(p(n))이 0에 가까울 수록 물체의 표면에 가까워졌다.

<br/>

### 조건

<br/>

- f(p(n)) < 0  
  - 물체 안에 있다.
- f(p(n)) = 0
  - 물체 표면에 있다.
- f(p(n)) > 0
  - 물체 밖에 있다, 충돌 방지 X

<br/>

![Intersection of Ray and implicit surface](https://user-images.githubusercontent.com/53526987/106744895-b2a6bf80-6663-11eb-8dd1-5168e4d8a212.PNG)

<br/>

### 정밀도 보완 방법(Bisection Method)

<br/>

- 이분할 방법
- 딱 0으로 떨어지는 값보다는 작은 값을 설정하여 해당 값에 가깝게 한다.

<br/>

![bisection method](https://user-images.githubusercontent.com/53526987/106745389-5db77900-6664-11eb-883b-941f0eb33d3f.PNG)

<br/>





----------------------------------------





<br/>

## RGB (Pixel 값 설정)

<br/>

| color \ type   | double | unsigned char |
| :----: | :------: | :-------------: |
|  RED    |  (1.0f, 0, 0)    |   (255, 0, 0)       |
|  GREEN  |   (0, 1.0f, 0)     |     (0, 255, 0)    |
|  BLUE   |   (0, 0, 1.0f)     |    (0, 0, 255)  |

<br/>

## Image Format

<br/>

- RGB color 값의 2차원 values

<br/>

## BMP

<br/>

- bit map 디지털 그림을 저장하는 데 쓰이는 그림 파일 포맷

- 빛과 물체가 상호작용해서 색의 값을 결정하는 과정

<br/>

![BMP](https://user-images.githubusercontent.com/53526987/106746544-0b775780-6666-11eb-8c47-4123026e1f95.PNG)

<br/>





------------------------------





<br/>

# Shading Model

<br/>

## Phong Reflection Model

<br/>

- 빛이 반사되면서 어떤 색 값을 띄는 가
- 빛이 눈으로 들어 왔을 때 어떤 색 값을 보여주는가

<br/>

![phong reflection model](https://user-images.githubusercontent.com/53526987/106746908-87719f80-6666-11eb-9a70-e96dd9848e1f.PNG)

<br/>

- L 과 R이 가까울 수록 빛이 많이 반사된다.(사이 각이 작을 수록)
  - ex) 거울에 직선으로 빛을 비췄을 때 반사되는 빛이 가장 쎄다

<br/>

### Vector

<br/>

### 1. V

- P(collision) -> P(camera)
- 물체와 ray의 충돌 지점으로 부터 카메라로 빛을 쏴주는 것
- 눈이 어디 방향에 있는지 알 수 있다(normalize, 정규화 해줘야 한다.)

<br/>

### 2. Surface normal (N)

- 수직 방향 normal vector
- surface의 기하학적 특성에서 부터 결정이 된다.(물체를 modeling하고 결정)

<br/>

### 3. Light vector (L)

- 충돌 지점에서 봤을 때 광원이 어디에 있는지를 나타내는 vector

<br/>

### 4. Perfect Reflection vector (R)

- 완전 반사 방향
- V(1번)의 반대 방향
- 빛이 들어오면 어디로 반사될 것인지 나타내는 vector

<br/>





---------------------------------





<br/>

## Perfect Reflection vector

<br/>

- normal vector(N)을 기준으로 봤을 때 입사각과 반사각이 같은 경우

<br/>

![Perfect_Reflection_Vector](https://user-images.githubusercontent.com/53526987/106747764-afadce00-6667-11eb-8d7b-19b89ebb57f5.PNG)

<br/>

### Red vector

<br/>

- V를 surface normal vector(N)에 projection 해준 것

<br/>

### Blue vector

<br/>

- V에서 Red vector을 빼준 것

<br/>

### R vector

<br/>

- V에서 Blue vector를 2번 빼준 것

<br/>



### +

#### Projection (투사)

<br/>

- 물체의 그림자를 어떤 물체 위에 비추는 일 or 그 비친 그림자
- 도형이나 입체를 다른 평면에 옮기는 일

<br/>

![projection](https://user-images.githubusercontent.com/53526987/106748185-306cca00-6668-11eb-81b5-74bf024b59ea.png)

출처: https://blueskyvision.tistory.com/236

<br/>

- 벡터 b를 벡터 a에 투영시킨 결과 => 투영벡터 p

<br/>





-----------------------------------------------





<br/>

## Phong Shadow Model

<br/>

- 빛이 표면으로 부터 반사가 되고 우리 눈에 들어 올 때 어떻게 보이는지 3가지로 나눈 것
- I: 빛(조명)에서 설정
- K: 표면의 성질
- a: 빛이 얼마나 반짝 거리는지

<br/>

![phong_shadow](https://user-images.githubusercontent.com/53526987/106748436-91949d80-6668-11eb-876d-7b1a1b711f3e.PNG)

<br/>

### 1. Ambient

<br/>

- 빛이 있으면 이런 색을 나타낸다.
- 광원들은 사방으로 펴져나가는 형태이기 때문에 빛이 반사되고 돌고돌면서 전체적으로 밝아진다 이러한 효과를 표현하기 위해 Ambient가 있다.

<br/>

### 2. Diffuse

<br/>

- 표면 위에 부딪친 빛이 사방으로 골고루 퍼져 나가는 것

<br/>

### 3. Specular

<br/>

- 표면 위에 부딪친 빛이 완전 반사각 방향으로 강하게 펴져 나가는 것 (반짝)

<br/>





----------------------------------------



<br/>



## Projection Model

<br/>

![projection model](https://user-images.githubusercontent.com/53526987/106748902-3911d000-6669-11eb-832e-1dd82b9b469f.PNG)

<br/>

### Orthogonal projection

<br/>

- Screen 부터 수직인 애들만 쏴준다.
- 치수가 정확하다
- CAD 등에서 사용

<br/>

### Perspective projection

<br/>

- 사람의 눈 위치로 부터 쏴준다.
- 치수가 정확하지 않는다.

<br/>



출처: 

<https://blog.naver.com/atelierjpro>

<https://www.youtube.com/watch?v=IUaiCl3GUVs>

