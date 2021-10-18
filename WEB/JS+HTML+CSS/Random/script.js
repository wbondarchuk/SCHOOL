var RNumber;
var RTries;
limit = 50;

function Random() 
{
today = new Date();
num = today.getTime();
num = Math.round(Math.abs(Math.sin(num) * 1000000)) % limit;
return num;
}

function Init(){
RNumber = Random();
RTries = 0;
document.FGame.Output.value='Угадай число от 0 до ' + (limit-1) +' ...';
document.FGame.Tries.value=RTries;
document.FGame.HighLow.value='';
document.FGame.Input.value='';
}

function Game(Number) {
if(Number==RNumber) 
{
RTries++;
document.FGame.Output.value='Вы догадались с ' + RTries + ' попытки! Это было ' 
+ RNumber + '! Нажмите "Старт", чтобы играть снова.';
document.FGame.HighLow.value='ПРАВИЛЬНО!';
}
else {
	RTries++;
    document.FGame.Output.value='Нет, ' + Number + ' - это не то число, о котором я думаю!';
    document.FGame.HighLow.value=(RNumber > Number) ? 'Больше!' : 'Поменьше!';
    document.FGame.Tries.value=RTries;
   }
}