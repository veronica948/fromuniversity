var ViewModel = function() {
	var self = this;
    self.description = ko.observable("Main page");
    self.title = ko.observable("Main");
	self.pageTitle = ko.computed(function() {
	    return self.title() + " " + self.description();
		}, this);
	self.footerTitle = 'Veronica Haritonova(task menu)';
	
   self.menu = ko.observableArray([
		{title:'Main',url:'main.html'},
		{title:'List2',url:'list2.html'},
		{title:'List3',url:'list3.html'},
		{title:'List4',url:'list4.html'}
	]);
	
	self.loadMenuPage = function(menuItem) {
		loadPage(menuItem.url);
		self.title(menuItem.title);
	};
};

function loadPage(page) {
	  $.ajax({
		  url: page,

		  type: "GET",
		  success: function( html ) {
			  $("#content").html( html );
			  onLoad2();
		  },
		  error: function( xhr, status ) {
			  console.log( "Sorry, there was a problem!" );
		  },
		  complete: function( xhr, status ) {
			  console.log( "The request is complete!" );
		  }
	  });
}
