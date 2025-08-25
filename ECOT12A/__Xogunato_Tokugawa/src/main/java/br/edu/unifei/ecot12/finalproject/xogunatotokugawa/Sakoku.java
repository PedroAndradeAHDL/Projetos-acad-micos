package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

public class Sakoku extends Social_Policy {

	@Override
	public void toggleChristianity()
	{
		getChristianity().getFreedom().turnOver(this.getChristianity());
	}

	@Override
	public void toggleBuddhism() {
		
		getBuddhism().getFreedom().turnOver(this.getBuddhism());
		
	}

	@Override
	public void toggleShintoism() {
		
		getShintoism().getFreedom().turnOver(this.getShintoism());
		
	}
}
