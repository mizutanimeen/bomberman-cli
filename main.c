#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <mmsystem.h>

#define GYO 15		/* マップの行数 */
#define RETU 21		/* マップの列数 */
char nickname[1000];
/* マップデータ */
int map_1[GYO][RETU] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 2, 0, 2, 2, 2, 2, 0, 1},
	{1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1},
	{1, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 1},
	{1, 2, 1, 0, 1, 0, 1, 2, 1, 2, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 1},
	{1, 2, 1, 0, 1, 2, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 2, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 2, 2, 1},
	{1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1},
	{1, 2, 2, 2, 2, 0, 0, 0, 2, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1},
	{1, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 1},
	{1, 2, 1, 2, 1, 0, 1, 2, 1, 2, 1, 0, 1, 2, 1, 0, 1, 2, 1, 0, 1},
	{1, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 2, 0, 2, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int map_2[GYO][RETU] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1},
	{1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 2, 1, 0, 1},
	{1, 0, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 0, 0, 1},
	{1, 2, 1, 0, 1, 0, 1, 2, 1, 2, 1, 2, 1, 0, 1, 0, 1, 2, 1, 0, 1},
	{1, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 2, 0, 2, 2, 2, 0, 0, 0, 0, 1},
	{1, 2, 1, 0, 1, 2, 1, 2, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 2, 2, 1},
	{1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 2, 1, 0, 1, 0, 1, 2, 1},
	{1, 2, 2, 2, 2, 0, 0, 0, 2, 2, 0, 0, 0, 2, 0, 0, 0, 2, 2, 2, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 2, 1, 0, 1, 0, 1, 2, 1},
	{1, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2, 2, 2, 1},
	{1, 0, 1, 2, 1, 0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0, 1, 2, 1, 0, 1},
	{1, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
int map[GYO][RETU];

//ブロックの見た目
char cellAA[][5+1] = {
	"　",// CELL_TYPE_NONE
	"■",// CELL_TYPE_HARD_BLOCK
	"□",// CELL_TYPE_SOFT_BLOCK
	"爆",//CELL_TYPE_BOMB
	"※",//CELL_TYPE_BLAST
};
//アイテムの見た目
char itemAA[][3+1] = {
	"Ｈ", //have
	"Ｐ", //power
	"Ｃ", //count
};
//定数
#define HAVE_BOMB_MAX (5)
#define BOMB_COUNT (5)
#define ENEMY_NUM (3)
#define ITEM_NUM (5)
#define ITEM_TYPE (3)
//構造体
typedef struct {
	int x;
	int y;
	int count;
}Bomb;
typedef struct {
	int x;
	int y;
	int power;
	int have_bomb;
	int life;
}Player;
typedef struct {
	int x;
	int y;
	int live;
}Enemy;
typedef struct {
	int x;
	int y;
	int type;
}Item;
//構造体の初期化
Player player = {1,1,1,1,3};
Enemy enemy[ENEMY_NUM] = {{3,4,1},{10,11,1},{7,9,1}};
Bomb bomb[HAVE_BOMB_MAX] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
Item item[ITEM_NUM] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
void name_command(){
	char name1[10] = "きんに君";
	char name2[18] = "ボマー捕まえた";
	int i = 0;int flag1 = 0;int flag2 = 0;int k = 0;
	
	if(strlen(nickname) != strlen(name1)){
		flag1 = 1;
	}
	
	if(strlen(nickname) != strlen(name2)){
		flag2 = 1;
	}

	while(nickname[i]!='\0' && name1[i]!='\0'){
		if(nickname[i]!=name1[i]){
			flag1 = 1;
			break;
		}
		i++;
	}
	i = 0;
	while(nickname[k]!='\0' && name2[k]!='\0'){
		if(nickname[k]!=name2[k]){
			flag2 = 1;
			break;
		}
		k++;
	}	
	if(flag1==0){
		player.power = 100;
		player.life = 500;
		player.have_bomb = 5;
		
	}
	if(flag2==0){
		system("cls");
		printf("命の音（カウントダウン）解除");
		player.have_bomb = 0;
		while(1){if(getch() == '\r'){break;}}
	}
}
//名前
void namescan(){
	system("cls");
	printf("プレイヤーの名前:");scanf("%s",nickname);
	name_command();
}

//ステージ１のミッション２のアイテム獲得判定
int item_get_m2 = 1;
//ボムの初期カウント数
int bomb_count = BOMB_COUNT;
//現在のステージ
int stage = 1;
//始めたときの時間と終わった時の時間
double start_time = 0;
double clear_time = 0;

//TopPageから遷移するゲーム説明ページ
void InfoPage(){
	system("cls");
	printf("-ルール-\n");
	printf("　　マップにいるすべての敵を爆弾で倒したらクリア！\n");
	printf("　　敵にぶつかったり爆発に巻き込まれると死亡！\n");
	printf("　　残機が１つ減ってスタート地点から再スタート！\n");
	printf("　　残機は３！\n");
	printf("\n");
	printf("-アイテム-\n");
	printf("　・Ｐ\n");
	printf("　　爆発の範囲を1マスずつ拡大！\n");
	printf("　・Ｈ\n");
	printf("　　使用可能な爆弾の数が一つずつ追加！\n");
	printf("　・Ｃ\n");
	printf("　　爆弾の爆発カウントを1カウントずつ遅延！\n");
	printf("\n");
	printf("\n");
	printf("Enterで戻る\n");
	while(1){if(getch() == '\r'){break;}}
}
	
//ステージ開始前のスタート画面
void TopPage(char *m1,char *m2,char *m3){
	system("cls");
	printf(
	"\x1b[47m　　　　　　　　\x1b[40m　　\x1b[47m　　　　　　　　　\x1b[47m　　　　　　　　　　　　　　　　\x1b[47m\n"
	"　　　　　　　\x1b[40m　\x1b[41m　　\x1b[40m　\x1b[47m　　　　　　　\x1b[47m　\x1b[40m　　　　　　　　　　　　\x1b[47m　　　　\x1b[47m\n"
	"　　　　　\x1b[40m　　　　　　　　\x1b[47m　　　　　\x1b[47m　\x1b[40m　　　　　　　　　　　　\x1b[47m　　　　\x1b[47m\n"
	"　　　　\x1b[40m　\x1b[47m　　　　　　　　\x1b[40m　\x1b[47m　　　　\x1b[47m　\x1b[40m　　 \x1b[31m\x1b[1mEnterでスタート　　\x1b[47m　　　　\x1b[47m\n"
	"　　　\x1b[40m　\x1b[47m　\x1b[43m　　　　　　　　\x1b[47m　\x1b[40m　\x1b[47m　　　\x1b[47m　\x1b[40m　　　　　　　　　　　　\x1b[47m　　　　\x1b[47m\n"
	"　　　\x1b[40m　\x1b[47m　\x1b[43m　\x1b[40m　\x1b[43m　　　　\x1b[40m　\x1b[43m　\x1b[47m　\x1b[40m　\x1b[47m　　　　\x1b[40m　　　　　　　　　　　　\x1b[47m　　　　\n"
	"　　　\x1b[40m　\x1b[47m　\x1b[43m　\x1b[40m　\x1b[43m　　　　\x1b[40m　\x1b[43m　\x1b[47m　\x1b[40m　\x1b[47m　　　　　　　　　　　　　　　　　　　　\n"
	"　　　\x1b[40m　\x1b[47m　\x1b[43m　\x1b[40m　\x1b[43m　　　　\x1b[40m　\x1b[43m　\x1b[47m　\x1b[40m　\x1b[47m　　　　　　　　　　　　　　　　　　　　\n"
	"　　　\x1b[40m　\x1b[47m　\x1b[43m　　　　　　　　\x1b[47m　\x1b[40m　\x1b[47m　　　　　　　　　　　　　　　　　　　　\n"
	"　　　　\x1b[40m　\x1b[47m　　　　　　　　\x1b[40m　\x1b[47m　　　　　　　　　　　　　　　　　　　　　\n"
	"　　　　\x1b[40m　　　　　　　　　　\x1b[47m　　　　　　　　　　　　　　　　　　　　　\n"
	"　　\x1b[40m　　\x1b[47m　\x1b[40m　\x1b[44m　　　　　　\x1b[40m　\x1b[47m　\x1b[40m　　\x1b[47m　　　　　　　　　　　　　　　　　　　\n"
	"　\x1b[40m　\x1b[41m　　\x1b[47m　\x1b[40m　　　\x1b[43m　　\x1b[40m　　　\x1b[47m　\x1b[41m　　\x1b[40m　\x1b[47m　　　　　　　　　　　　　　　　　　\n"
	"　\x1b[40m　\x1b[41m　　\x1b[40m　\x1b[41m　　\x1b[44m　　　　\x1b[41m　　\x1b[40m　\x1b[41m　　\x1b[40m　\x1b[47m　　　　　　　　　　　　　　　　　　\n"
	"　\x1b[47m　\x1b[40m　　\x1b[41m　　　　\x1b[40m　　\x1b[41m　　　　\x1b[40m　　\x1b[47m　　　　　　　　　　　　　　　　　　　\n"
	"　\x1b[47m　　\x1b[40m　　　　　\x1b[47m　\x1b[40m　　　　　　\x1b[47m　　　　　　　　　　　　　　　　　　　　\n"
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\x1b[49m\x1b[39m	\x1b[0m\n");	
	puts("");
	printf("ステージ%d\n",stage);
	printf("ミッション１： %s\n",m1);
	printf("ミッション２： %s\n",m2);
	printf("ミッション３： %s\n",m3);
	printf("\n");
	printf("qで説明を見る\n");
	while(1){
		int key = getch();
		if(key == '\r'){
			break;
		} else if(key == 113){//q
			InfoPage();
			TopPage(m1,m2,m3);
			break;
		}
	}
}
//ゲームオーバーになった時に遷移するページ
void GameOverPage(void){
	system("cls");
	printf(
	"　　　　　　　■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■\n"
	"　　　　　　■□□■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　■\n"
	"　　　　■■■■■■■■　　　■　　　 %sさん、ＧＡＭＥＯＶＥＲ　　　　　　　　■\n"
	"　　　■□□□□□□□□■　　■　　　　次はクリアしよう…　　　　　　　　　　■\n"
	"　　■□　　　　　　　　□■　■　　　　　　　　　　　　　　　　　　　　　　　■\n"
	"　　■□　■　　　　■　□■　■■■■■■■■■■■■■■■■■■■■■■■■\n"
	"　　■□　　■　　■　　□■　　　　　　　　\n"
	"　　■□　■　　　　■　□■　　　　　　　　\n"
	"　　■□　　　　　　　　□■　　　　　　　　\n"
	"　　　■□□□□□□□□■　　　　　　　　　\n"
	"　　　■■■■■■■■■■　　　　　　　　　\n"
	"　■■□■◆◆◆◆◆◆■□■■　　　　　　　\n"
	"■　　□■■■　　■■■□　　■　　　　　　\n"
	"■　　■　　◆◆◆◆　　■　　■　　　　　　\n"
	"　■■　　　　■■　　　　■■　　　　　　　\n"
	"　　■■■■■　■■■■■■　　　　　　　　\n",nickname);
	exit(1);
}
//ステージクリア後に遷移するページ
void ResultPage(int m1,int m2,int m3){
	system("cls");
	printf(
	"　　　　　　　■■　　　　　　　■■■■■■■■■■■■\n"
	"　　　　　　■□□■　　　　　■　　　　　　　　　　　■\n"
	"　　　　■■■■■■■■　　　■　　ステージクリア　　■\n"
	"　　　■□□□□□□□□■　　■　　　　　　　　　　　■\n"
	"　　■□　　　　　　　　□■　■■■■■■■■■■■■　\n"
	"　　■□　■　　　　■　□■　　　　　　　　\n"
	"　　■□　■　　　■　　□■　　　　　　　　\n"
	"　　■□　■　　　　■　□■　　　　　　　　\n"
	"　　■□　　　　　　　　□■　　　　　　　　\n"
	"　　　■□□□□□□□□■　　　　　　　　　\n"
	"　　　■■■■■■■■■■　　　　　　　　　\n"
	"　■■□■◆◆◆◆◆◆■□■■　　　　　　　\n"
	"■　　□■■■　　■■■□　　■　　　　　　\n"
	"■　　■　　◆◆◆◆　　■　　■　　　　　　\n"
	"　■■　　　　■■　　　　■■　　　　　　　\n"
	"　　■■■■■　■■■■■■　　　　　　　　\n");
	printf("クリアタイム： %5.1f\n",(clear_time-start_time)/1000);
	if(m1){
		printf("ミッション１：達成\n");
	} else {
		printf("ミッション１：未達成\n");
	}
	if(m2){
		printf("ミッション２：達成\n");
	}else {
		printf("ミッション２：未達成\n");
	}
	if(m3){
		printf("ミッション３：達成\n");
	}else {
		printf("ミッション３：未達成\n");
	}
	printf("Enterで次へ\n");
	while(1){if(getch() == '\r'){break;}}
}
//全ステージクリア後のページ
void ClearPage(void){
	system("cls");
	printf(
	"　　　　　　　■■　　　　　　　■■■■■■■■■■■■\n"
	"　　　　　　■□□■　　　　　■　　　　　　　　　　　■\n"
	"　　　　■■■■■■■■　　　■　　　おめでとう　　　■\n"
	"　　　■□□□□□□□□■　　■　　　　　　　　　　　■\n"
	"　　■□　　　　　　　　□■　■■■■■■■■■■■■　\n"
	"　　■□　■　　　　■　□■　　　　　　　　\n"
	"　　■□　■　　　■　　□■　　　　　　　　\n"
	"　　■□　■　　　　■　□■　　　　　　　　\n"
	"　　■□　　　　　　　　□■　　　　　　　　\n"
	"　　　■□□□□□□□□■　　　　　　　　　\n"
	"　　　■■■■■■■■■■　　　　　　　　　\n"
	"　■■□■◆◆◆◆◆◆■□■■　　　　　　　\n"
	"■　　□■■■　　■■■□　　■　　　　　　\n"
	"■　　■　　◆◆◆◆　　■　　■　　　　　　\n"
	"　■■　　　　■■　　　　■■　　　　　　　\n"
	"　　■■■■■　■■■■■■　　　　　　　　\n");
	printf("全ステージクリア\n");
}
//メニュー
void print_menu(){
	printf("\n");
	printf("　Player: %s\n",nickname);
	printf("　Stage: %d\n",stage);
	printf("　Time: %5.1f\n",(clock()-start_time)/1000);
	printf("　life: %d\n",player.life);
	printf("　Bomb: %d/%d\n",player.have_bomb,HAVE_BOMB_MAX);
	printf("　Power: %d\n",player.power);
	printf("　Bomb Count: %d\n",bomb_count);
	printf("\n");
	printf("-------------------------\n");
	printf("\n");
	printf("　移動: w a s d\n");	/* 操作説明 */
	printf("　爆弾設置:enter\n");
	printf("　終了:esc\n");
}
//爆風をすべて削除
void reset_explosion(){
	for(int y=0; y<GYO; y++){ 
		for(int x=0; x<RETU; x++){
			if(map[y][x] == 4){map[y][x]=0;}
		}
	}
}

//ダメージを受けたか、ゲームオーバーかどうか確認
void check_damage_gameover(void){
	for(int i = 0; i< ENEMY_NUM; i++){
		if(!enemy[i].live){continue;}
		if(player.x == enemy[i].x && player.y == enemy[i].y){
			player.life--;
			player.x = 1;
			player.y = 1;
			reset_explosion();
			if(player.life <= 0){
				GameOverPage();
			}
		}
	}
	if(map[player.y][player.x] == 4){
		player.life--;
		player.x = 1;
		player.y = 1;
		reset_explosion();
		if(player.life <= 0){
			GameOverPage();
		}
	}
}
//引数の数字を全角文字としてプリント
void print_bomb_count(int count){
	switch (count)
	{
	case 1: 
		printf("１");
		break;
	case 2:
		printf("２");
		break;
	case 3:
		printf("３");
		break;
	case 4:
		printf("４");
		break;
	case 5:
		printf("５");
		break;
	case 6:
		printf("６");
		break;
	case 7:
		printf("７");
		break;
	case 8:
		printf("８");
		break;
	case 9:
		printf("９");
	default:
		printf("爆");
	}
}
//引数x,yの位置に存在するbomのindexを返す
int can_print_bomb_index(int x,int y){
	for(int i = 0; i< player.have_bomb; i++){
		if(x == bomb[i].x && y == bomb[i].y){
			return i;
		}
	}
	return -1;
}
//現在、使っていないボムのindexを返す
int can_use_bomb_index(void){
	for(int i = 0; i < player.have_bomb; i++){
		if(bomb[i].count < 0){
			return i;
		}
	}
	return -1;
}
//bombのカウントを全部１減らす
void count_down_bomb(void){
	for(int i = 0; i< player.have_bomb; i++){
		bomb[i].count--;
	}
}
//引数x,yの位置に存在するenemyのindexを返す
int can_print_enemy_index(int x,int y){
	for(int i = 0; i< ENEMY_NUM; i++){
		if(x == enemy[i].x && y == enemy[i].y){
			return i;
		}
	}
	return -1;
}
//現在、使っていないアイテムのindexを返す
int can_use_item_index(){
	for(int i = 0; i < ITEM_NUM; i++){
		if(item[i].type == -1){
			return i;
		}
	}
	return -1;
}
//引数x,yの位置に存在するitemのindexを返す
int can_print_item_index(int x,int y){
	for(int i = 0; i< ITEM_NUM; i++){
		if(x == item[i].x && y == item[i].y){
			return i;
		}
	}
	return -1;
}

void item_create(int bx,int by,int px, int py,int p){
	int item_index = can_use_item_index(); //アイテム表示に空きがあるか
	if(item_index != -1){
		if((time(NULL)+(rand() % 7 + 1))%5 >= 3){ //アイテム生成
			item[item_index].type = (time(NULL)+(rand() % 7 + 1))%ITEM_TYPE;
			item[item_index].x = bx+px*p;
			item[item_index].y = by+py*p;
		}
	}
}

//爆風を表示
void explosion(int bx,int by,int px, int py,int index){
	int flag = 1;
	bomb[index].count = -1;
	for(int p=0; p<=player.power; p++){
		if(map[by+py*p][bx+px*p] != 1 && flag == 1){
			for(int i = 0; i<ITEM_NUM;i++){
				if(item[i].y == by+py*p && bx+px*p == item[i].x){
					item[i].type = -1;
					item[i].y = -1;
					item[i].x = -1;
				}
			}
			if(map[by+py*p][bx+px*p] == 2){ //破壊可能ブロックを一つ壊したら止める
				flag = 0;
				item_create(bx,by,px,py,p);
			}
			map[by+py*p][bx+px*p] = 4; //爆風を描画
			for(int i = 0; i< ENEMY_NUM; i++){ // 敵の倒す判定
				if(by+py*p==enemy[i].y && bx+px*p == enemy[i].x){
					enemy[i].live = 0;
				}
			}
			if(by+py*p==player.y && bx+px*p ==player.x){//プレイヤーの死ぬ判定
				player.life--;
				player.x = 1;
				player.y = 1;
				reset_explosion();
				if(player.life <= 0){
					GameOverPage();
				}
			}
			for(int i=0; i<player.have_bomb;i++){
				if(by+py*p == bomb[i].y && bx+px*p == bomb[i].x && bomb[i].count >= 0){ // 爆弾に当たったらその爆弾も爆破
					bomb[i].count = 0;
					if(index > i){
						int a = bomb[i].x;
						int b = bomb[i].y;
						explosion(a,b,1,0,i);
						explosion(a,b,-1,0,i);
						explosion(a,b,0,1,i);
						explosion(a,b,0,-1,i);
					}
				}
			}
		} else {
			break;
		}
	}
}

/* マップを表示 */
void draw_map(void)
{
	system("cls");
	for(int i=0;i<player.have_bomb;i++){ // 爆弾のカウントが０なら爆発させる.
		if(bomb[i].count == 0){
			int bx = bomb[i].x;
			int by = bomb[i].y;
			explosion(bx,by,1,0,i);
			explosion(bx,by,-1,0,i);
			explosion(bx,by,0,1,i);
			explosion(bx,by,0,-1,i);
		}
	}
	for(int y=0; y<GYO; y++){
		for(int x=0; x<RETU; x++){
			if (map[y][x] == 4){
				printf(cellAA[map[y][x]]);
			}else if(can_print_enemy_index(x,y) != -1){
				if(enemy[can_print_enemy_index(x,y)].live){
					printf("敵");
				} else {
					if(x == player.x && y == player.y){
						printf("人");
						
					}else if(can_print_item_index(x,y) != -1){
						printf(itemAA[item[can_print_item_index(x,y)].type]);
					} else {
						printf(cellAA[0]);
					}
				}
			}else if(x == player.x && y == player.y){
				printf("人");
			}else if(can_print_item_index(x,y) != -1){
				printf(itemAA[item[can_print_item_index(x,y)].type]);
			}else if(can_print_bomb_index(x,y) != -1){
				int index = can_print_bomb_index(x,y);//この座標のボムのインデックスを取得
				map[y][x] = 3; //ボム設置
				if (bomb[index].count <= 0){ //カウントが0以下のボムは表示しない
					map[y][x] = 0;
					printf(cellAA[0]);
				} else {
					print_bomb_count(bomb[index].count); //ボムのカウントを表示
				}
			} else {
				printf(cellAA[map[y][x]]);//マップの番号のブロックを表示
			}
		}
		printf("\n");
	}
	print_menu();
}

int enemy_not_conflict(int index,int x,int y){
	for(int i = 0; i< ENEMY_NUM; i++){
		if (index == i){ continue; }
		if(enemy[i].x == (enemy[index].x + x) && enemy[i].y == enemy[index].y + y){
			return 0; //False 他の敵と位置が被る
		}
	}
	return 1; // True
}
//敵の行動パターン（適当）
void enemy_move(void){
	for(int i = 0; i< ENEMY_NUM; i++){
		//移動先が何もない場所(0)かつ他の敵がいないか確認
		//行動パターンを時間によって変更
		switch((time(NULL)+i+(rand() % 10 + 1))%4){
			case 0:
				if(map[enemy[i].y][enemy[i].x+1] == 0 && enemy_not_conflict(i,1,0))
					enemy[i].x++;
				else if(map[enemy[i].y+1][enemy[i].x] == 0 && enemy_not_conflict(i,0,1))
					enemy[i].y++;
				else if(map[enemy[i].y][enemy[i].x-1] == 0 && enemy_not_conflict(i,-1,0))
					enemy[i].x--;
				else if(map[enemy[i].y-1][enemy[i].x] == 0 && enemy_not_conflict(i,0,-1))
					enemy[i].y--;
				break;
			case 1:
				if(map[enemy[i].y+1][enemy[i].x] == 0 && enemy_not_conflict(i,0,1))
					enemy[i].y++;
				else if(map[enemy[i].y][enemy[i].x-1] == 0 && enemy_not_conflict(i,-1,0))
					enemy[i].x--;
				else if(map[enemy[i].y-1][enemy[i].x] == 0 && enemy_not_conflict(i,0,-1))
					enemy[i].y--;
				else if(map[enemy[i].y][enemy[i].x+1] == 0 && enemy_not_conflict(i,1,0))
					enemy[i].x++;
				break;
			case 2:
				if(map[enemy[i].y][enemy[i].x-1] == 0 && enemy_not_conflict(i,-1,0))
					enemy[i].x--;
				else if(map[enemy[i].y-1][enemy[i].x] == 0 && enemy_not_conflict(i,0,-1))
					enemy[i].y--;
				else if(map[enemy[i].y][enemy[i].x+1] == 0 && enemy_not_conflict(i,1,0))
					enemy[i].x++;
				else if(map[enemy[i].y+1][enemy[i].x] == 0 && enemy_not_conflict(i,0,1))
					enemy[i].y++;
				break;
			case 3:
				if(map[enemy[i].y-1][enemy[i].x] == 0 && enemy_not_conflict(i,0,-1))
					enemy[i].y--;
				else if(map[enemy[i].y][enemy[i].x+1] == 0 && enemy_not_conflict(i,1,0))
					enemy[i].x++;
				else if(map[enemy[i].y+1][enemy[i].x] == 0 && enemy_not_conflict(i,0,1))
					enemy[i].y++;
				else if(map[enemy[i].y][enemy[i].x-1] == 0 && enemy_not_conflict(i,-1,0))
					enemy[i].x--;
				break;
		}
	}
}
//クリア判定
int clear_check(){
	for(int i=0;i<ENEMY_NUM;i++){
		if(enemy[i].live){
			return 0;
		}
	}
	return 1;
}

/* プレイヤー行動のためのキー入力受付 */
void key_input(int key)
{
	//移動先が何もない場所か確認
	if(key == 119 && map[player.y-1][player.x] == 0 || map[player.y-1][player.x] == 4)			/* wキー */
		player.y --;
	else if(key == 115 && map[player.y+1][player.x] == 0 || map[player.y+1][player.x] == 4)		/* sキー */
		player.y ++;
	else if(key == 97 && map[player.y][player.x-1] == 0 || map[player.y][player.x-1] == 4)		/* aキー */
		player.x --;
	else if(key == 100 && (map[player.y][player.x+1] == 0 || map[player.y][player.x+1] == 4))		/* dキー */
		player.x ++;
	else if(key == '\r' && can_use_bomb_index() != -1){ /* enterキー */  
		int index = can_use_bomb_index(); //使ってないボムを取得,初期設定
		bomb[index].x = player.x;
		bomb[index].y = player.y;
		map[player.y][player.x] = 3;
		bomb[index].count = bomb_count;
	}
	else if(key == 27){exit(1);}/* escキー */
}

void item_get_check(){
	for(int i = 0; i < ITEM_NUM; i++){
		if(item[i].x == player.x && item[i].y == player.y){
			switch (item[i].type)
			{
			case 0:
				if(player.have_bomb<HAVE_BOMB_MAX){
					player.have_bomb++;
				}
				break;
			case 1:
				player.power++;
				break;
			case 2:
				bomb_count++;
				break;
			}
			item[i].x = -1;
			item[i].y = -1;
			item[i].type = -1;
			item_get_m2 = 0;
		}
	}
}

void main_game(char *m1,char *m2,char *m3,double roop_time) {
	TopPage(m1,m2,m3);
	bomb_count = BOMB_COUNT;
	draw_map();	/* マップを表示 */
	double base_time = 0;
	start_time = clock();
	while(1){
		if(clock()-base_time >= roop_time){
			base_time = clock();
			enemy_move();/* 敵移動 */
			check_damage_gameover();//ゲームオーバーかどうか確認
			count_down_bomb();//ボムのカウントを進める
			reset_explosion();
			draw_map();	/* マップを表示 */
		}
		if(clear_check()){
			clear_time = clock();
			break;
		}//クリアチェック
		if ( kbhit() ){
			key_input(getch());/* プレイヤー行動のためのキー入力受付 */
			item_get_check();//アイテム取得
			check_damage_gameover();//ゲームオーバーかどうか確認
			draw_map();	/* マップを表示 */
		}
	}
}

void bomb_set(void){
	for(int i = 0; i < HAVE_BOMB_MAX; i++){
		bomb[i].x = -1;
		bomb[i].y = -1;
		bomb[i].count = -1;
	}
}
void item_set(void){
	for(int i = 0; i < ITEM_NUM; i++){
		item[i].x = -1;
		item[i].y = -1;
		item[i].type = -1;
	}
}
void enemy_set(int index,int x,int y){
	enemy[index].x = x;
	enemy[index].y = y;
	enemy[index].live = 1;
}
void player_set(){
	player.x = 1;
	player.y = 1;
	player.have_bomb = 1;
	player.power = 1;
	player.life = 3;
}

int main(void)
{
	//ココでmap_2とか作ってランダムにすればマップランダムにできる
	srand(time(NULL));
	int i = rand() % 2;
	if(i == 0){
		memcpy(map, map_2, sizeof(map_2));
	}
	else{
		memcpy(map, map_1, sizeof(map_1));
	}

	//ステージ１
	namescan();
	enemy[1].live = 0;
	main_game("60秒以内にクリア","アイテムを１つも取らずにクリア","１度もやられずにクリア",500.0);
	//ミッション達成判定
	int r1=0,r2=0,r3=0;
	if((clear_time-start_time)/1000 <= 60){r1 = 1;}
	if(item_get_m2){r2 = 1;}
	if(player.life == 3){r3 = 1;}
	ResultPage(r1,r2,r3);


	if(i == 0){
		memcpy(map, map_1, sizeof(map_1));
	}
	else{
		memcpy(map, map_2, sizeof(map_2));
	}
	stage++;
	item_get_m2 = 1;
	player_set();
	enemy_set(0,3,4);enemy_set(1,7,8);enemy_set(2,10,11);
	bomb_set();
	item_set();
	name_command();
	//ステージ２
	main_game("90秒以内にクリア","アイテムを１つも取らずにクリア","１度もやられずにクリア",300.0);
	//ミッション達成判定
	r1=0,r2=0,r3=0;
	if((clear_time-start_time)/1000 <= 90){r1 = 1;}
	if(item_get_m2){r2 = 1;}
	if(player.life == 3){r3 = 1;}
	ResultPage(r1,r2,r3);

	ClearPage();
	return 0;
}

//メモ
//残機を増やすアイテムつくる？
//残機をステージ変わっても引き継ぐ？
