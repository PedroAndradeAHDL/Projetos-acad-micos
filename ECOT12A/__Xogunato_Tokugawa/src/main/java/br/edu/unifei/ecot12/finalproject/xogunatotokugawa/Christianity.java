package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

public class Christianity extends Religion {

	@Override
	public Religion myClone() {
		Religion r = new Christianity(); 
		r.setSacredText(this.getSacredText());
		r.setSacredSymbol(this.getSacredSymbol());
		r.setEntityFollowed(this.getEntityFollowed());
		
		
		return r;
	}

}
