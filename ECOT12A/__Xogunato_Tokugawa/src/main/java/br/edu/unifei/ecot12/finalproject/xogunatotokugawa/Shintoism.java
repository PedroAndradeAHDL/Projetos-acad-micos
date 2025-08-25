package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

public class Shintoism extends Religion {

	@Override
	public Religion myClone() {
		Religion r = new Shintoism(); 
		r.setSacredText(this.getSacredText());
		r.setSacredSymbol(this.getSacredSymbol());
		r.setEntityFollowed(this.getEntityFollowed());
		
		
		return r;
	}

}
