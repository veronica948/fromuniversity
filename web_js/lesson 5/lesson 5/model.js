var ViewModel = function() {
	var self = this;
    self.description = ko.observable("Knockout, построение шаблонных страниц");
    self.title = ko.observable("Урок 9");
	self.pageTitle = ko.computed(function() {
	    return self.title() + " " + self.description();
		}, this);
		
    self.menu = ko.observableArray([
		{title:'Урок 6.1',url:'page1.html'},
		{title:'Урок 6.2',url:'page2.html'},
		{title:'Урок 7',url:'page3.html'}
	]);
	
	self.loadMenuPage = function(menuItem) {
		loadPage(menuItem.url);
		self.title(menuItem.title);
	};
};