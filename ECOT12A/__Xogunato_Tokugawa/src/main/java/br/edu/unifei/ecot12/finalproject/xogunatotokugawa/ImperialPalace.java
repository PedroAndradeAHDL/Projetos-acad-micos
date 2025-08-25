package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

public class ImperialPalace {
	
	private String location;
	
	private Emperor emperor;
	
	public boolean requestPoliticalAction(String action)
	{
		return emperor.politicalAction(action);
	}

	public String getLocation() {
		return location;
	}

	public void setLocation(String location) {
		this.location = location;
	}

	public Emperor getEmperor() {
		return emperor;
	}

	public void setEmperor(Emperor emperor) {
		this.emperor = emperor;
	}

}
