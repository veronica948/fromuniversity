$( document ).ready(onLoad);

function onLoad() {


	var htmlTop = document.getElementById("htmlTop");
	var model = new ViewModel();
	ko.applyBindings(model, htmlTop);
	model.loadMenuPage(model.menu()[0]);
	
	//$("#menu a").bind("click",function() {
				 //loadPage($(this).attr("href"));
				 //return false;
			//});
	
	$("#dataKeeper").click(function() {
			$(this).css("background-color","yellow");
		});
}
function loadPage(page) {
$.ajax({
    url: page,
    type: "GET",
    success: function( html ) {
        $("#content").html( html );
    } 
});
}
