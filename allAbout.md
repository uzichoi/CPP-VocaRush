✅ VocaRush: 콘솔 기반 2인 단어 배틀 게임
🧭 프로젝트 개요
개발 환경: C++ (콘솔 기반)

주요 개념: 객체지향 설계, 키 입력 이벤트 처리, 게임 루프 관리

게임 유형: 2인 대전형 단어 추리 게임

구현 방식: 각 기능을 분리한 클래스로 구성, 화면은 gotoxy와 텍스트 박스 기반 시각화

🔧 핵심 시스템 설명
1. 🔁 게임 흐름 (GameController::run)
startGame() → configurateGame() → drawGameScreen() → handleTurn() 반복

모든 단어를 찾거나 양쪽 플레이어가 모두 사망할 때 종료

2. 👥 턴 관리 시스템
assignTurn()을 통해 A(L) 키를 누른 플레이어에게 턴 부여

단, HP가 0인 플레이어는 입력해도 무시 (삑 소리로 피드백 제공)

cpp
복사
편집
if ((key == 'a' || key == 'A') && player[0].getHP() > 0) return 0;
else Beep(750, 150);  // 죽은 플레이어가 입력했을 경우
3. 💬 단어 입력 및 판별
키 입력 → 단어 입력창 → 입력값을 word 리스트에서 판별

정답이면: markFound(), 점수 100점 추가, 콤보 증가

오답이면: combo 리셋 + HP 감소

cpp
복사
편집
if (!word.isFound() && word.getText() == input) {
	word.markFound();
	current.addScore(100);
	current.addCombo();
}
4. 🧱 시각적 구성 (View 클래스 분리)
GameScreenView, PlayerView, InputBoardView, ConfigurationView 등 화면 역할별로 View 클래스 분리

gotoxy(), drawBox(), textcolor() 등으로 박스 UI 구성

입력 후 inputBoardView.clear() 또는 draw(true)로 시각적으로 입력창 초기화

5. 💀 사망 처리
getHP() <= 0인 플레이어는 assignTurn()에서 입력 무시

사망한 플레이어는 더 이상 점수를 얻을 수 없으며, View 갱신 시 정보만 유지됨

6. 🏁 종료 조건
모든 단어가 isFound() == true일 경우

두 플레이어 모두 HP가 0일 경우