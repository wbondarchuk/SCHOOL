var name1 = "Игрок 1";
var name2 = "Игрок 2";

var massOfX = new Array(); // массив клеток с "х"
var massOfO = new Array(); // массив клеток с "0"

document.getElementById('name1').innerHTML = name1;
document.getElementById('name2').innerHTML = name2;

function saveName() {
	alert("Новые имена приняты!");

	var newName1 = document.getElementById('cont1').value;
	var newName2 = document.getElementById('cont2').value;

	document.getElementById('name1').innerHTML = newName1;
	document.getElementById('name2').innerHTML = newName2;
}

var modal = document.getElementById("myModal");

var saveBtn = document.getElementById("save");

var edit = document.getElementById("edit");

edit.onclick = function() {
  modal.style.display = "block";
}

saveBtn.onclick = function() {
  modal.style.display = "none";
  saveName();
}

window.onclick = function(event) {
  if (event.target == modal) {
    modal.style.display = "none";
  }
}

var count = 0;

document.onclick = function(event) {

	if (event.target.classList.contains('cell')) {


		var idField = event.target.id
		var field = document.getElementById(idField)

		if ((count % 2) == 0) {
			if (field.dataset.pip == "") {
				field.dataset.pip = '1';
				displaySponge(idField + 1);
				massOfX.push(idField);
				count++;			
			} 
			else {
				alert("Занято");
			}
		} else {

			if (field.dataset.pip == "") {
				field.dataset.pip = '0';
				displayPatric(idField + 0);
				massOfO.push(idField);
				count++;
			} else {
				alert("Занято");
			}

		}

		if (count == 9) {
			var button = document.getElementById("result");
			button.style.display = "block";
		}

		}
	}

function displaySponge(idImage) {
  var image = document.getElementById(idImage);
  image.style.display = "block";
}
function displayPatric(idImage) {
  var image = document.getElementById(idImage);
  image.style.display = "block";
}

function result() {

	let name1 = document.getElementById('name1').innerHTML;
	let name2 = document.getElementById('name2').innerHTML;

	if (massOfX.indexOf( '1' ) != -1 && massOfX.indexOf( '2' ) != -1 && massOfX.indexOf( '3' ) != -1) {
		alert("Выиграл " + name1);		
	} else if (massOfX.indexOf( '4' ) != -1 && massOfX.indexOf( '5' ) != -1 && massOfX.indexOf( '6' ) != -1) {
		alert("Выиграл " + name1);		
	} else if (massOfX.indexOf( '7' ) != -1 && massOfX.indexOf( '8' ) != -1 && massOfX.indexOf( '9' ) != -1) {
		alert("Выиграл " + name1);

	} else if (massOfX.indexOf( '1' ) != -1 && massOfX.indexOf( '4' ) != -1 && massOfX.indexOf( '7' ) != -1) {
		alert("Выиграл " + name1);
	} else if (massOfX.indexOf( '2' ) != -1 && massOfX.indexOf( '5' ) != -1 && massOfX.indexOf( '8' ) != -1) {
		alert("Выиграл " + name1);
	} else if (massOfX.indexOf( '3' ) != -1 && massOfX.indexOf( '6' ) != -1 && massOfX.indexOf( '9' ) != -1) {
		alert("Выиграл " + name1);

	} else if (massOfX.indexOf( '1' ) != -1 && massOfX.indexOf( '5' ) != -1 && massOfX.indexOf( '9' ) != -1) {
		alert("Выиграл " + name1);
	} else if (massOfX.indexOf( '3' ) != -1 && massOfX.indexOf( '5' ) != -1 && massOfX.indexOf( '7' ) != -1) {
		alert("Выиграл " + name1);
	}

	// Такая же проверка и для второго игрока
	else if (massOfO.indexOf( '1' ) != -1 && massOfO.indexOf( '2' ) != -1 && massOfO.indexOf( '3' ) != -1) {
		alert("Выиграл " + name2);
	} else if (massOfO.indexOf( '4' ) != -1 && massOfO.indexOf( '5' ) != -1 && massOfO.indexOf( '6' ) != -1) {
		alert("Выиграл " + name2);
	} else if (massOfO.indexOf( '7' ) != -1 && massOfO.indexOf( '8' ) != -1 && massOfO.indexOf( '9' ) != -1) {
		alert("Выиграл " + name2);

	} else if (massOfO.indexOf( '1' ) != -1 && massOfO.indexOf( '4' ) != -1 && massOfO.indexOf( '7' ) != -1) {
		alert("Выиграл " + name2);
	} else if (massOfO.indexOf( '2' ) != -1 && massOfO.indexOf( '5' ) != -1 && massOfO.indexOf( '8' ) != -1) {
		alert("Выиграл " + name2);
	} else if (massOfO.indexOf( '3' ) != -1 && massOfO.indexOf( '6' ) != -1 && massOfO.indexOf( '9' ) != -1) {
		alert("Выиграл " + name2);

	} else if (massOfO.indexOf( '1' ) != -1 && massOfO.indexOf( '5' ) != -1 && massOfO.indexOf( '9' ) != -1) {
		alert("Выиграл " + name2);
	} else if (massOfO.indexOf( '3' ) != -1 && massOfO.indexOf( '5' ) != -1 && massOfO.indexOf( '7' ) != -1) {
		alert("Выиграл " + name2);
	}
	// Если совпадений не было, значит никто не выиграл
	else {
		alert("Ничья");
	}

}


