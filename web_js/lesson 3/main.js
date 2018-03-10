function moveButton() {
	//this.style.marginTop = parseInt(this.style.marginTop)-5+'px';
	alert(this.style);
}

function onLoad() {
	var dataK = document.getElementById('dataKeeper');
	dataK.onmouseover = function() {
		dataK.style.color = 'red';
	};

	<!-- используя существующую функцию -->

	function dataK_mouseout() {
		this.style.color = 'black';
	}

	dataK.onmouseout = dataK_mouseout;

	
}

