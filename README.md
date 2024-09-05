# 🚗 Arduino 기반 RC 카 프로젝트

## 📖 프로젝트 소개 (Project Overview)

이 프로젝트는 웹 개발자가 되기 전에 기술을 쌓기 위해 진행한 Arduino 기반의 RC 카 프로젝트입니다. 복잡한 회로 조립과 Arduino 시스템 프로그래밍은 학교에서 배우지 않은 영역이었지만, 개인적으로 매우 값진 경험이었습니다.

Android Studio를 사용하여 블루투스 통신이 가능한 간단한 앱을 개발하였고, 이를 통해 RC 카를 수동으로 조종할 수 있는 기능을 구현했습니다. 또한, RC 카의 앞쪽에 장착된 초음파 센서를 통해 자율 주행 기능을 추가하여, RC 카가 스스로 장애물을 회피하며 주행할 수 있도록 했습니다.

## 🎯 프로젝트의 목표 (Project Goals)

이 프로젝트의 주된 목표는 Arduino와 Android Studio를 통해 하드웨어와 소프트웨어 간의 통합을 경험하고, IoT 및 임베디드 시스템 개발의 기본 개념을 이해하는 것이었습니다.
비록 웹 개발과 직접적인 연관은 없지만, 이 프로젝트는 다양한 기술을 습득하고 실제 하드웨어와 상호작용하는 소프트웨어를 개발하는 데 중요한 경험이 되었습니다.

## 🌟 주요 기능 (Key Features)

### RC 카 조종
Android 앱을 사용하여 RC 카를 수동으로 조종할 수 있습니다.
### 자율 주행
RC 카 앞에 장착된 초음파 센서를 사용하여 장애물을 감지하고 자율적으로 주행합니다.
### 블루투스 통신
Android 앱과 RC 카 간의 블루투스 통신을 통해 명령을 전송하고 수신합니다.

## 🛠️ 기술 스택 (Tech Stack)

![Arduino](https://img.shields.io/badge/Arduino-%2300979D.svg?style=for-the-badge&logo=arduino&logoColor=white)
![Android Studio](https://img.shields.io/badge/Android%20Studio-%233DDC84.svg?style=for-the-badge&logo=android-studio&logoColor=white)
![C/C++](https://img.shields.io/badge/C/C++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Bluetooth](https://img.shields.io/badge/Bluetooth-%230A84FF.svg?style=for-the-badge&logo=bluetooth&logoColor=white)

## 🔧 설치 및 실행 방법 (Installation & Setup)

1. **Arduino 설정**:
   - Arduino IDE를 설치하고 필요한 라이브러리(예: 블루투스 통신, 초음파 센서)를 추가합니다.
   - Arduino 코드(.ino 파일)를 다운로드하고, Arduino 보드에 업로드합니다.

2. **Android 앱 설치**:
   - Android Studio에서 프로젝트를 열고, Android 기기 또는 에뮬레이터에 앱을 설치합니다.

3. **RC 카 조립**:
   - 제공된 회로도를 참고하여 Arduino 보드, 모터 드라이버, 초음파 센서 등을 연결합니다.

4. **연결 및 테스트**:
   - Android 앱에서 블루투스 연결을 설정한 후, RC 카를 수동으로 조종하거나 자율 주행 모드를 테스트합니다.

## 📚 사용법 (Usage)

1. **앱을 실행**:
   - Android 기기에서 앱을 실행하고, RC 카와 블루투스 연결을 설정합니다.
2. **RC 카 조종**:
   - 앱의 컨트롤을 사용하여 RC 카를 수동으로 조종할 수 있습니다.
3. **자율 주행 모드 활성화**:
   - 앱에서 자율 주행 모드를 선택하면, RC 카가 초음파 센서를 이용하여 장애물을 회피하며 자율적으로 주행합니다.
